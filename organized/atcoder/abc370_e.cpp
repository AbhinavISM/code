#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int32_t main(){
	fast_io;
	int t = 1;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> a(n,0);
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		if(n==1&&a[0]==k) {
			cout<<1;
			continue;
		}
		int ans = 0;
		vector<int> f(n,0);
		map<int, vector<int>> mp;
		for(int i = 0; i<n; i++){
			if(i>0) f[i] = f[i-1] + a[i];
			else f[i] = a[i];
			mp[f[i]].push_back(i);
		}
		for(auto it : mp){
			cout<<it.first<<" : ";
			peek(it.second)
		}
		
		cout<<((1<<(n-1))-ans);
	}
	return 0;
}