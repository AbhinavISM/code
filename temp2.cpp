#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>  // For sqrt(), erf()
using namespace std;

// Structure to store activity details
struct Activity {
    string name;
    double to, tm, tp, te, sigma;
    vector<string> predecessors;
    double est = 0, eft = 0, lst = 0, lft = 0;
    double totalFloat = 0, freeFloat = 0;
};

// Global Variables
map<string, Activity> activities;
map<string, vector<string>> successors;
double projectCompletionTime = 0;
double projectVariance = 0;

// Function to compute expected time (Te) and standard deviation (σ)
void calculateTeAndSigma() {
    for (auto &[name, activity] : activities) {
        activity.te = (activity.to + 4 * activity.tm + activity.tp) / 6.0;
        activity.sigma = (activity.tp - activity.to) / 6.0;
    }
}

// Compute Earliest Start (EST) and Earliest Finish (EFT)
void calculateEST_EFT() {
    queue<string> q;
    map<string, int> inDegree;

    for (auto &[name, activity] : activities) {
        inDegree[name] = activity.predecessors.size();
        if (activity.predecessors.empty()) q.push(name);
    }

    while (!q.empty()) {
        string current = q.front();
        q.pop();
        Activity &act = activities[current];

        act.eft = act.est + act.te;
        projectCompletionTime = max(projectCompletionTime, act.eft);

        for (string &succ : successors[current]) {
            activities[succ].est = max(activities[succ].est, act.eft);
            if (--inDegree[succ] == 0) q.push(succ);
        }
    }
}

// Compute Latest Start (LST) and Latest Finish (LFT)
void calculateLST_LFT() {
    queue<string> q;
    map<string, int> outDegree;

    for (auto &[name, activity] : activities) {
        activity.lft = projectCompletionTime;
        outDegree[name] = successors[name].size();
        if (successors[name].empty()) q.push(name);
    }

    while (!q.empty()) {
        string current = q.front();
        q.pop();
        Activity &act = activities[current];

        act.lst = act.lft - act.te;

        for (string &pred : act.predecessors) {
            activities[pred].lft = min(activities[pred].lft, act.lst);
            if (--outDegree[pred] == 0) q.push(pred);
        }
    }
}

// Compute Total Float and Free Float
void calculateFloats() {
    for (auto &[name, activity] : activities) {
        activity.totalFloat = activity.lft - activity.eft;

        double minESTSuccessor = projectCompletionTime;
        for (string &succ : successors[name]) {
            minESTSuccessor = min(minESTSuccessor, activities[succ].est);
        }

        activity.freeFloat = (successors[name].empty()) ? activity.totalFloat : minESTSuccessor - activity.eft;
    }
}

// Find Critical Path and Compute Project Variance
vector<string> findCriticalPath() {
    vector<string> criticalPath;
    projectVariance = 0;

    for (auto &[name, activity] : activities) {
        if (activity.totalFloat == 0) {
            criticalPath.push_back(name);
            projectVariance += pow(activity.sigma, 2); // Sum of variances along critical path
        }
    }
    return criticalPath;
}

// Function to calculate probability using standard normal distribution
double calculateProbability(double deadline) {
    double projectStdDev = sqrt(projectVariance);
    double Z = (deadline - projectCompletionTime) / projectStdDev;

    // Use the cumulative distribution function (CDF) for normal distribution
    double probability = 0.5 * (1 + erf(Z / sqrt(2))); // Approximate probability
    return probability * 100; // Convert to percentage
}

// Main function
int main() {
    // Hardcoded activity details (To, Tm, Tp)
    activities["A"] = {"A", 3, 4, 5, 0, 0, {}};
    activities["B"] = {"B", 2, 3, 4, 0, 0, {"A"}};
    activities["C"] = {"C", 4, 5, 6, 0, 0, {"A"}};
    activities["D"] = {"D", 2, 3, 4, 0, 0, {"B", "C"}};
    activities["E"] = {"E", 3, 4, 5, 0, 0, {"C"}};
    activities["F"] = {"F", 5, 6, 7, 0, 0, {"D", "E"}};

    // Populate successors based on predecessors
    for (auto &[name, activity] : activities) {
        for (const string &pred : activity.predecessors) {
            successors[pred].push_back(name);
        }
    }

    // Perform calculations
    calculateTeAndSigma();
    calculateEST_EFT();
    calculateLST_LFT();
    calculateFloats();

    // Display Activity Details
    cout << "\nActivity Details:\n";
    cout << "Name\tTo\tTm\tTp\tTe\tσ\tEST\tEFT\tLST\tLFT\tTF\tFF\n";
    for (auto &[name, activity] : activities) {
        cout << name << "\t" << activity.to << "\t" << activity.tm << "\t"
             << activity.tp << "\t" << activity.te << "\t" << activity.sigma << "\t"
             << activity.est << "\t" << activity.eft << "\t" << activity.lst << "\t"
             << activity.lft << "\t" << activity.totalFloat << "\t" << activity.freeFloat << "\n";
    }

    // Find and display Critical Path
    vector<string> criticalPath = findCriticalPath();
    cout << "\nCritical Path: ";
    for (string &act : criticalPath) cout << act << " ";
   
    cout << "\nProject Completion Time (Te): " << projectCompletionTime;
    cout << "\nProject Standard Deviation (σ): " << sqrt(projectVariance) << "\n";

    // Input deadline for probability calculation
    double deadline=21;
   

    // Calculate and display probability
    double probability = calculateProbability(deadline);
    cout << "Probability of completing the project within " << deadline << " days: " << probability << "%\n";

    return 0;
}