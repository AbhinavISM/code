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
	int x;
	cin>>x;
	int k;
	cin>>k;
	int digitsum = 0;
	int ans = x;
	int temp = ans;
	while(temp!=0){
		digitsum += temp%10;
		temp/=10;
	}
	while(digitsum%k!=0){
		digitsum = 0;
		ans += 1;
		temp = ans;
		while(temp!=0){
			digitsum += temp%10;
			temp/=10;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}