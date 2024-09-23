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
	if(k>=30){
		k = 30;
	}
	if(x>=(1<<k)){
		cout<<(1<<k)<<"\n";
	} else {
		cout<<x+1<<"\n";
	}
}
	return 0;
}