#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n,q;
	cin>>n>>q;
	vector<vector<int>> cost(n, vector<int>(60,0));
	vector<vector<bool>> bits(n, vector<bool>(60,false));
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		for(int j = 59; j>=0; j--){
			bits[i][j] = ((item%2==1)?true:false);
			item/=2;
		}
		int smolai = 0;
		for(int j = 59; j>=0; j--){
			if(!bits[i][j]){
				cost[i][j] = (1ll<<(59-j)) - smolai;
			} else {
				smolai += (1ll<<(59-j));
			}
		}
	}

	while(q--){
		int k;
		cin>>k;
		// vector<bool> final(60,false);
		int ans = 0;
		vector<int> done;
		for(int b = 0; b<=59; b++){
			int netcost = 0;
			for(int i = 0; i<n; i++){
				bool blasted = false;
				for(int j : done){
					if(!bits[i][j]){
						blasted = true;
					}
				}
				if(blasted) {netcost += (1ll<<(59-b));}
				else {netcost += cost[i][b];}
				if(netcost>k){break;}
			}
			if(netcost<=k){
				k-=netcost;
				ans += (1ll<<(59-b));
				done.push_back(b);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}