#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void solve(){
	int n,k,m;
	cin>>n>>k>>m;
	string s;
	cin>>s;
	s = '0'+s;
	vector<vector<int>> next(m+1,vector<int>(k,-1));
	for(int i = m-1; i>=0; i--){
		for(int j = 0; j<k; j++){
			next[i][j] = next[i+1][j];
		}
		next[i][s[i+1]-'a'] = i+1;
	}
	int j = 0;
	string ans = "";
	bool flag = false;
	for(int i = 1; i<=n; i++){
		int maxi = -1;
		for(int l = 0; l<k; l++){
			maxi = max(maxi, next[j][l]);
			if(next[j][l]==-1){
				flag = true;
				for(; i<=n; i++){
					ans += (char)('a'+l);
				}
				break;
			}
		}
		if(flag){
			break;
		}
		ans += s[maxi];
		j=maxi;
	}
	if(flag){
		cout<<"NO\n";
		cout<<ans<<"\n";
	} else {
		cout<<"YES\n";
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	solve();
}
	return 0;
}