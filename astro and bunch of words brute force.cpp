#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<ll> i : v) {for(ll j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
void checkPermutations(ll idx, vector<string> &p, ll &ans){
	if(idx==p.size()){
		return;
	}
	string toCheck = "";
	for(string &s : p){
		toCheck.append(s);		
	}
	ll i = 0; ll j = toCheck.length()-1;
	bool isPalindrome = true;
	while(i<j){
		if(toCheck[i]==toCheck[j]){i++;j--;}
		else {isPalindrome = false; break;}
	}
	if(isPalindrome) ans = max(ans, (ll)toCheck.length());
	for(ll i = idx+1; i<p.size(); i++){
		swap(p[idx], p[i]);
		checkPermutations(idx+1,p,ans);
		swap(p[idx], p[i]);
	}
}
ll maxConcatenatedPalindrome(vector<string>& words){
	ll ans = 0;
	ll n = words.size();
	for(ll i = (1ll<<n)-1; i>=0; i--){
		vector<string> p;
		for(ll j = 0; j<n; j++){
			if(i&(1ll<<j)) p.push_back(words[j]);
		}
		checkPermutations(0,p,ans);
	}
	return ans;
}
int main(){
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