// {i, a, at, in, sat, sin, sing, stat, state, sting, string, estate, restate, restated, restarted, resharpen, staring, starling}
// longest chain length is 9 : restarted, restated, restate, estate, state, stat, sat, at, a
#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
pair<int,int> findLongestChain(int n, string word, vector<string> &words,
 map<string, pair<int,int>> &dp, map<string, int> &stringToIndex){
	if(word.size()==0) return {0,-1};
	if(dp[word].first!=0) return dp[word];
	int ans = 1;
	int longestChildIdx = -1;
	for(int i = 0; i<word.length(); i++){
		string newWord = "";
		for(int j = 0; j<word.length(); j++){
			if(i!=j) newWord += word[j];
		}
		if(dp.find(newWord)!=dp.end()){
			pair<int,int> subsetResult = findLongestChain(n, newWord, words, dp, stringToIndex);
			int subsetLongestChain = subsetResult.first;
			int childidx = stringToIndex[newWord];
			if(subsetLongestChain+1>ans){
				ans = subsetLongestChain + 1;
				longestChildIdx = childidx;
			}
		}
	}
	return dp[word] = {ans, longestChildIdx};
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<string> words(n);
	map<string, int> stringToIndex;
	for(int i = 0; i<n; i++){
		cin>>words[i];
		stringToIndex[words[i]] = i;
	}
	map<string, pair<int, int>> dp;
	for(string word : words){
		dp[word] = {0,-1};
	}
	int longestChain = 0;
	int longestChildIdx = -1;
	for(string word : words){
		pair<int, int> result = findLongestChain(n, word, words, dp, stringToIndex);
		longestChain = max(longestChain, result.first);
		longestChildIdx = result.second;		
	}
	cout<<longestChain<<"\n";
	// for(auto it : dp) cout<<it.first<<" "<<it.second<<"\n";
	return 0;
}