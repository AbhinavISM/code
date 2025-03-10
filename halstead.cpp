#include<bits/stdc++.h>
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int main() {
    string filename = "example.cpp";
    set<string> operatorSet = {"+", "-", "*", "/", "<", ">", "<=", ">=", "++", "--", "&&", "||"};
    map<string, bool> operandSet;
    int N1 = 0, N2 = 0;

    ifstream file(filename);

    string word = "";
    string lastword = "";
    string lastlastword = "";
    bool operatorFound = false;
    while (file >> word) {
        if(operatorFound){
            if(lastword!="++" && lastword!="--"){
                operandSet[word] = true;
                operandSet[lastlastword] = true;
                N1 = N1 + 2;
                N2 = N2 + 1;
            } else {
                N1 = N1 + 1;
                N2 = N2 + 1;
            }
        }
        operatorFound = false;
        if (operatorSet.find(word) == operatorSet.end()) {
            operatorFound = true;
        }
        lastlastword = lastword;
        lastword = word;
    }

    int n1 = operatorSet.size(), n2 = operandSet.size(), n = n1 + n2, N = N1 + N2;
    double V = N * log2(n);
    double D = (((double)n1) / 2.0) * (((double)N2) / ((double)n2));
    double E = D * V;

    cout << "Vocabulary: " << n << "\n";
    cout << "Length: " << N << "\n";
    cout << "Volume: " << V << "\n";
    cout << "Difficulty: " << D << "\n";
    cout << "Effort: " << E << "\n";
    return 0;
}