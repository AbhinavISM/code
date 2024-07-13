#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
int find(string &a, string &b){
	int n = a.length(); int m = b.length();
	int i = 0;
	int ans = INT_MAX;
	for(int j = 0; j<m; j++){
		while(i<n&&a[i]!=b[j]){
			i++;
		}
		if(i==n) return -1;
		ans = min(ans,i);
	}
	return ans;
}
int32_t main(){
	fast_io;
	string a,b;
	cin>>a; cin>>b;
	int n = a.length();
	int m = b.length();
	int ans = INT_MAX;
	for(int i=1; i<m; i++){
		for(int j =  0; j<26; j++){
			char t = b[i];
			b[i] = (char)('a'+j);
			if(find(a,b)!=-1){
				ans = min(ans, find(a,b));
			}
			b[i] = t;
		}
	}
	if(ans!=INT_MAX) cout<<ans+1;
	else cout<<-1;
	return 0;
}