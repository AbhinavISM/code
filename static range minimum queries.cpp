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
	int n;
	cin>>n;
	int t;
	cin>>t;
	vector<int> a(n+1,0);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	vector<vector<int>> sparse(n+1, vector<int>(25,INT64_MAX));
	//sparse[i][j] = min from [i i+2^j) (right non inclusive)
	for(int i = 1; i<=n; i++){
		sparse[i][0] = a[i];
	}
	for(int i = n; i>=1; i--){
		for(int j = 1; j<25; j++){
			if(i+(1<<j)-1<=n) sparse[i][j] = min(sparse[i][j-1], sparse[i + (1<<(j-1))][j-1]);
		}
	}
	// dpeek(sparse)
	vector<int> logs(n+1,0);
	for(int i = 2; i<=n; i++){
		logs[i] = logs[i/2] + 1;
	}
	while(t--){
	int i,j;
	cin>>i>>j;
	int len = j-i+1;
	int ans = min(sparse[i][logs[len]], sparse[j - (1<<(logs[len])) + 1][logs[len]]);
	cout<<ans<<"\n";
}
	return 0;
}