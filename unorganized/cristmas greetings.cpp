#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	if(n==1){
		cout<<1<<"\n";
		continue;
	}
	if(n%2==0){
		cout<<-1<<"\n";
		continue;
	}
	vector<vector<int>> ans(n,vector<int>(n,0));
	ans[0][0] = 1;
	int odd = 3;
	int even = 2;
	for(int i = 1; i<n; i++){
		for(int j = 0; j<i&&odd<=n*n; j++){
			ans[i][j] = odd;
			odd+=4;
		}
	}
	odd = 5;
	for(int j = 1; j<n; j++){
		for(int i = 0; i<j&&odd<=n*n; i++){
			ans[i][j] = odd;
			odd+=4;
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(ans[i][j]==0){
				ans[i][j] = even;
				even+=2;
			}
		}
	}
	for(int i = 0; i<n; i++){
		peek(ans[i])
	}
}
	return 0;
}