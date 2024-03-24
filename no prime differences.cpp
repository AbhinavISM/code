#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> base(n,vector<int>(m));
	int num = 1;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			base[i][j] = num;
			num++;
		}
	}
	if(m%2==0){
		dpeek(base)
		continue;
	} else if(n%2==0){
		int num = 1;
		for(int i = 0; i<m; i++){
			for(int j = 0; j<n; j++){
				base[j][i] = num;
				num++;
			}
		}
		dpeek(base)
		continue;
	}
	vector<vector<int>> ans;
	for(int i = 0; i<(n/2); i++){
		ans.push_back(base[i]);
		ans.push_back(base[n-i-1]);
	}
	peek(base[(n)/2])
	dpeek(ans)
}
	return 0;
}