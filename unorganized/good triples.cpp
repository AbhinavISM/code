#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	vector<int> fuck(10);
	for(int i = 0; i<10; i++){
		fuck[i] = (i+1)*(i+2);
		fuck[i]/=2;
	}
	while(t--){
	int n;
	cin>>n;
	int ans = 1;
	while(n>0){
		ans *= fuck[n%10];
		n/=10;
	}
	cout<<ans<<"\n";
}
	return 0;
}