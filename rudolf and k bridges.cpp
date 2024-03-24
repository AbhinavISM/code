#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(int i = 1; i<v.size(); i++) cout<<v[i]<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m,k,d;
	cin>>n>>m>>k>>d;
	vector<vector<int>> depth(n+1, vector<int>(m+1));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin>>depth[i][j];
		}
	}
	vector<int> minarr(n+1);
	for(int i = 1; i<=n; i++){
		multiset<int> ms;
		vector<int> mshelp(m+1);
		mshelp[1] = 1;
		ms.insert(1);
		for(int j = 2; j<=m; j++){
			if(j-d-1<1){
				ms.insert(depth[i][j] + 1 + 1);
				mshelp[j] = depth[i][j] + 1 + 1;
			} else {
				mshelp[j] = (*ms.begin()) + depth[i][j] + 1;
				ms.insert(mshelp[j]);
				ms.erase(ms.find(mshelp[j-d-1]));
			}
		}
		minarr[i] = mshelp[m];
	}
	int ans = INT64_MAX;
	for(int i = 1; i<=n; i++){
		if(i+k<=n+1){
			int minians = 0;
			for(int j = i; j<i+k; j++){
				minians += minarr[j];
			}
			ans = min(ans,minians);
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}