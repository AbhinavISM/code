#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
void checkPermutations(int idx, vector<string> &p, int &ans){
	if(idx==p.size()){
		return;
	}
	string toCheck = "";
	for(string &s : p){
		toCheck.append(s);		
	}
	int i = 0; int j = toCheck.length()-1;
	bool isPalindrome = true;
	while(i<j){
		if(toCheck[i]==toCheck[j]){i++;j--;}
		else {isPalindrome = false; break;}
	}
	if(isPalindrome) ans = max(ans, (int)toCheck.length());
	for(int i = idx+1; i<p.size(); i++){
		swap(p[idx], p[i]);
		checkPermutations(idx+1,p,ans);
		swap(p[idx], p[i]);
	}
}
int maxConcatenatedPalindrome(vector<string>& words){
	int ans = 0;
	int n = words.size();
	for(int i = (1ll<<n)-1; i>=0; i--){
		vector<string> p;
		for(int j = 0; j<n; j++){
			if(i&(1ll<<j)) p.push_back(words[j]);
		}
		checkPermutations(0,p,ans);
	}
	return ans;
}
int32_t main(){
	fast_io;
	vector<string> words1 = {"y", "xyx", "abc", "cba", "bac", "y", "y"};
    vector<string> words2 = {"y", "xyx", "abc", "cba", "bac", "y"};
    vector<string> words3 = {"ab", "ab", "xyx", "de","ba", "ba","tyyt"};
    vector<string> words4 = {"xy", "abc", "xyx", "bac", "cab", "cba"};
    vector<string> words5 = {"xyx","ab","ba"};

    cout << maxConcatenatedPalindrome(words1) << "\n";
    cout << maxConcatenatedPalindrome(words2) << "\n";
    cout << maxConcatenatedPalindrome(words3) << "\n";
    cout << maxConcatenatedPalindrome(words4) << "\n";
    cout << maxConcatenatedPalindrome(words5) << "\n";
}