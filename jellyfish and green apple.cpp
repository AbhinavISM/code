#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	
	int on = n;
	int om = m;

	if(n%m==0){
		cout<<0<<"\n";
		return;
	}

	n = n%m;
	int gcd = __gcd(n,m);
	m = m/gcd;
	n = n/gcd;

	bool set = false;
	int setbit = 0;
	for(int i = 0; i<=30; i+=1){
		if((1<<i)&m){
			if(!set){
				setbit = i;
				set = true;
			} else {
				cout<<-1<<"\n";
				return;
			}
		}
	}

	int ans = 0;
	for(int i = 1; i<= setbit; i++){
		ans += (on%om);
		on*=2;
		on%=om;
	}
	cout<<ans<<"\n";
	return;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();

}
	return 0;
}