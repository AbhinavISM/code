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
	int a,b,c;
	cin>>a>>b>>c;
	if(abs(b-c)%2==0){
		cout<<1<<" ";
	} else {
		cout<<0<<" ";
	}
	if(abs(a-c)%2==0){
		cout<<1<<" ";
	} else {
		cout<<0<<" ";
	}
	if(abs(b-a)%2==0){
		cout<<1<<" ";
	} else {
		cout<<0<<" ";
	}
	cout<<"\n";
}
	return 0;
}