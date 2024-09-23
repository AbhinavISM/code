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
	int a,b;
	cin>>a>>b;
	int xk,yk;
	cin>>xk>>yk;
	int xq,yq;
	cin>>xq>>yq;
	set<pair<int,int>> kingkill;
	set<pair<int,int>> queenkill;
	kingkill.insert({xk + a, yk + b});
	kingkill.insert({xk - a, yk + b});
	kingkill.insert({xk + a, yk - b});
	kingkill.insert({xk - a, yk - b});
	kingkill.insert({xk + b, yk + a});
	kingkill.insert({xk - b, yk + a});
	kingkill.insert({xk + b, yk - a});
	kingkill.insert({xk - b, yk - a});
	queenkill.insert({xq + a, yq + b});
	queenkill.insert({xq - a, yq + b});
	queenkill.insert({xq + a, yq - b});
	queenkill.insert({xq - a, yq - b});
	queenkill.insert({xq + b, yq + a});
	queenkill.insert({xq - b, yq + a});
	queenkill.insert({xq + b, yq - a});
	queenkill.insert({xq - b, yq - a});
	int ans = 0;
	for(auto i : kingkill){
		if(queenkill.find(i) != queenkill.end()){
			ans++;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}