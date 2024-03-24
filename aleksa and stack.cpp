#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	// cout<<3<<" "<<4<<" ";
	// int ai = 3;
	// int aip1 = 4;
	// for(int i = 3; i<=n; i++){
	// 	int ans = ai+aip1-1;
	// 	cout<<ans<<" ";
	// 	ai = aip1;
	// 	aip1 = ans;
	// }
	int init = 5;
	for(int i = 1; i<=n; i++){
		cout<<init<<" ";
		init++;
	}
	cout<<"\n";
}
	return 0;
}