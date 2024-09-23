#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int a,b,c;
	cin>>a>>b>>c;
	int ans = a;
	ans += b/3;
	if(b%3==0){
		ans += (c/3);
		if(c%3!=0) ans += 1;
		cout<<ans<<"\n";
	} else if(b%3==1&&c>=2){
		ans += 1;
		ans += (c-2)/3;
		if((c-2)%3!=0) ans += 1;
		cout<<ans<<"\n";
	} else if(b%3==2&&c>=1){
		ans += 1;
		ans += (c-1)/3;
		if(((c-1)%3)!=0) ans += 1;
		cout<<ans<<"\n";
	} else {
		cout<<-1<<"\n";
	}
}
	return 0;
}