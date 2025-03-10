#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
//ordered_set s;
//s.order_of_key(key) -> number of elements smaller than key in set
//*s.find_by_order(idx) -> element at index idx in set

int solve(string s){
	int n = s.length();
	int st = 0;
	while(st < n/2){
		if(s[st]==s[n-1-st]) {
			st++;
		} else {
			break;
		}
	}
	string ts = "";
	for(int i = st; i<=n-1-st; i++){
		ts += s[i];
	}
	s = ts;
	n = s.size();
	// peek(s)
	if(s.size()==0 || s.size()==1) {
		// cout<<"already palindrome ";
		return 0;
	}
	int ct = n/2-1;
	while(ct >= 0) {
		if(s[ct]==s[n-1-ct]) {
			ct--;
		} else {
			break;
		}
	}
	vector<int> f1(26, 0);
	for(int i = 0; i<=ct; i++){
		f1[s[i]-'a']++;
	}
	vector<int> f2(26, 0);
	for(int i = n-1-ct; i<n; i++){
		f2[s[i]-'a']++;
	}
	if(f1==f2) {
		// cout<<"smallest found ";
		return ct+1;
	}
	for(int i = ct+1; i<(n+1)/2; i++){
		f1[s[i]-'a']++;
	}
	for(int i = (n+1)/2; i<n-1-ct; i++){
		f2[s[i]-'a']++;
	}
	// peek(f1) peek(f2)
	bool oddfound = false;
	bool bad = false;
	for(int i = 0; i<26; i++){
		if(f1[i]>=f2[i]){
			if((f1[i]-f2[i])%2==1 && !oddfound) oddfound = true;
			else if((f1[i]-f2[i])%2==1) bad = true;
		} else {
			bad = true;
		}
	}
	int ans = INT_MAX;
	if(!bad) ans = min(ans, (n+1)/2);
	for(int i = (n+1)/2; i<n; i++){
		f1[s[i]-'a']++;
		f2[s[i]-'a']--;
		oddfound = false;
		bad = false;
		for(int j = 0; j<26; j++){
			if(f1[j]>=f2[j]){
				if((f1[j]-f2[j])%2==1 && !oddfound) oddfound = true;
				else if((f1[j]-f2[j])%2==1) bad = true;
			} else {
				bad = true;
			}
		}
		if(!bad) ans = min(ans, i+1);
	}
	// cout<<"general ";
	return ans;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int ans = solve(s);
		// cout<<ans<<"\n";
		reverse(s.begin(), s.end());
		ans = min(ans, solve(s));
		cout<<ans<<"\n";
	}
	return 0;
}