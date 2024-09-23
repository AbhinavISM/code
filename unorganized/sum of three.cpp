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
	if(n==1||n==2||n==3||n==4||n==5||n==6||n==9){
		cout<<"NO\n";
	}
	else if(n%3!=0){
		cout<<"YES\n";
		cout<<1<<" "<<2<<" "<<n-3<<"\n";
	} else {
		cout<<"YES\n";
		cout<<1<<" "<<4<<" "<<n-5<<"\n";
	}
}
	return 0;
}