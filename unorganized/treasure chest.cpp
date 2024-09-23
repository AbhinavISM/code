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
	int y;
	cin>>y;
	int k;
	cin>>k;
	if(x>=y){
		cout<<x<<"\n";
	} else if((k>=y-x)){
		cout<<y<<"\n";
	} else {
		cout<<y+(y-x-k)<<"\n";
	}
}
	return 0;
}