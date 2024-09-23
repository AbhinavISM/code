#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int maxConcatenatedPalindrome(vector<string>& words){
    map<string, int> mp;
    int len = 0;
    bool hasOddPalindrome = false;

    for(string& word : words) mp[word]++;

    int x = -1;

    for(auto& pair : mp){
        string word = pair.first;
        int wordCount = pair.second;

        int n = word.length();

        string temp = word;
        reverse(temp.begin(), temp.end());

        if(word == temp){
            if(wordCount % 2 == 0){
                len += (wordCount * n);
            } 
            else{
                len += (wordCount - 1) * n;
                x = n;
                hasOddPalindrome = true;
            }
        } 
        else if(mp.find(temp) != mp.end()){
            int tempCount = mp[temp];
            int pairs = min(wordCount, tempCount);
            len += pairs * 2 * n;
            mp[temp] = 0;
        }
    }

    if(hasOddPalindrome) len += x; //middle

    return len;
}

int main() {
    vector<string> words1 = {"y", "xyx", "abc", "cba", "bac", "y", "y"};
    vector<string> words2 = {"y", "xyx", "abc", "cba", "bac", "y"};
    vector<string> words3 = {"ab", "ab", "xyx", "de","ba", "ba","tyyt"};
    vector<string> words4 = {"xy", "abc", "xyx", "bac", "cab", "cba"};

    cout << maxConcatenatedPalindrome(words1) << "\n";
    cout << maxConcatenatedPalindrome(words2) << "\n";
    cout << maxConcatenatedPalindrome(words3) << "\n";
    cout << maxConcatenatedPalindrome(words4) << "\n";

    return 0;
}