#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m,k;
	cin>>n>>m>>k;
	map<int,int> af;
	map<int,int> bf;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
		if(i<m) af[a[i]]++;
	}
	vector<int> b(m,0);
	for(int i = 0; i<m; i++){
		cin>>b[i];
		bf[b[i]]++;
	}
	int matching = 0;
	for(auto it : bf){
		matching += min(it.second, af[it.first]);
	}
	int ans = 0;
	if(matching>=k) ans++;
	// cout<<matching<<"\n";
	int i = 1; int j = m;
	while(j<n){
		matching -= min(af[a[i-1]], bf[a[i-1]]);
		af[a[i-1]]--;
		matching += min(af[a[i-1]], bf[a[i-1]]);
		matching -= min(af[a[j]], bf[a[j]]);
		af[a[j]]++;
		matching += min(af[a[j]], bf[a[j]]);
		if(matching>=k) ans++;
		i++;
		j++;
	}
	cout<<ans<<"\n";
}
	return 0;
}