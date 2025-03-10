#include<bits/stdc++.h>
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int main() {
    string filename = "example.c";
    set<string> operatorSet = {"+", "-", "*", "/", "=", "==", "<", ">", "<=", ">=", "++", "--", "&&", "||", "!"};
    set<string> operandSet;

    int N1 = 0, N2 = 0;

    ifstream file(filename);

    string word;
    while (file >> word) {
        if (operatorSet.find(word) != operatorSet.end()) {
            N1++;
        } else {
            operandSet.insert(word);
            N2++;
        }
    }

    int n1 = operatorSet.size(), n2 = operandSet.size(), n = n1 + n2, N = N1 + N2;
    double V = N * log2(n);
    double D = (((double)n1) / 2.0) * (((double)N2) / ((double)n2));
    double E = D * V;

    cout << "Vocabulary: " << n << endl;
    cout << "Length: " << N << endl;
    cout << "Volume: " << V << endl;
    cout << "Difficulty: " << D << endl;
    cout << "Effort: " << E << endl;
    return 0;
}