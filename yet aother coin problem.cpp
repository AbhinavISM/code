#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int ans = INT64_MAX;
	int coins[] = {1,3,6,10,15};
	int need[] = {0,1,2,1,2,3,1,2,3,2,1,2,2,2,3,1};
	for(int i = 1; i<=15; i++){
		for(int j = 0; j<5; j++){
			if(n-i*coins[j]>=0){
				ans = min(ans, i + (n-i*coins[j])/15 + need[(n-i*coins[j])%15]);
			}
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}