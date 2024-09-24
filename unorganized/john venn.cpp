#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    multiset<string> set1;
    vector<string> common_elements;

    stringstream ss1(a), ss2(b);
    string element;

    while (ss1 >> element) {
        set1.insert(element);
    }

    while (ss2 >> element) {
        if (set1.find(element) != set1.end()) {
            common_elements.push_back(element);
            set1.erase(set1.find(element));
        }
    }

    if (!common_elements.empty()) {
        for (size_t i = 0; i < common_elements.size(); ++i) {
            if (i > 0) cout << " ";
            cout << common_elements[i];
        }
        cout << endl;
    } else {
        cout << "NULL" << endl;
    }

    return 0;
}