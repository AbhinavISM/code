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
	int n,k;
	cin>>n>>k;
	if(k>=n-1){
		cout<<1<<"\n";
		continue;
	}
	int cost = 0;
	int i = 1;
	for(i = 1; i<n; i++){
		cost += (n-i);
		// cout<<cost<<" ";
		if(cost>k){
			break;
		}
	}
	cout<<n-(i-1);
	cout<<"\n";
	// cout<<n-i<<"\n";
	// int ans = 0;
	// int i = 1;
	// while(k-(n-i)>=0){
	// 	k-=(n-i);
	// 	i++;
	// 	ans++;
	// }
	// cout<<n-ans<<"\n";

}
	return 0;
}	