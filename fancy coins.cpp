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
	int m;
	cin>>m;
	int k;
	cin>>k;
	int a1;
	cin>>a1;
	int ak;
	cin>>ak;
	int ans = 0;
	int kcount = m/k;
	int onecount = m%k;
	int kovf = ak-kcount;
	int oneovf = a1-onecount;
	kovf += oneovf/k;
	oneovf = oneovf%k;
	// while(oneovf>0&&kovf<0){
	// 	if(oneovf-k>=0){
	// 		kovf++;
	// 		oneovf = oneovf-k;
	// 	} else {
	// 		break;
	// 	}
	// }
	if(kovf<0){
		ans += (-1*kovf);
	}
	if(oneovf<0){
		ans += (-1*oneovf);
	}
	cout<<ans<<"\n";
}
	return 0;
}
