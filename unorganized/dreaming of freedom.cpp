#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
void solve(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	if(n==1||m==1){
		cout<<"YES\n";
		return;
	}
	if(n<=m){
		cout<<"NO\n";
		return;
	}
	if(n%2==0){
		cout<<"NO\n";
		return;
	}
	if(n%3==0&&m>=3){
		cout<<"NO\n";
		return;
	}
	for(int i = 2; i*i<=n; i++){
		if(n%i==0){
			if(m>=i){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
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