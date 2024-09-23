#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void update(vector<int> &BIT, int i, int n, int val){
	while(i<=n) {
		BIT[i] += val;
		i += (i^(-i));
	}
}
int query(vector<int> &BIT, int i){
	int ans = 0;
	while(i>0) {
		ans += BIT[i];
		i -= (i^(-i));
	}
	return ans;
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int t;
	cin>>t;
	vector<int> a(n+1,0);
	vector<int> BIT(n+1,0);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
		update(BIT, i, n, a[i]);
	}
	while(t--){
		int q;
		cin>>q;
		if(q==1) {
			int a,b,u;
			cin>>a>>b>>u;
			update(BIT, a, n, u);
			update(BIT, b, n, -u);
		} else {
			int k;
			cin>>k;
			cout<<query(BIT, k)<<"\n";
		}
}
	return 0;
}