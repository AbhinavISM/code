#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void update(vector<int> &BIT, int idx, int val, int n){
	//add value of a[i] to all parents
	//find parent by adding lsb to index.
	while(idx<=n){
		BIT[idx] += val;
		idx += ((idx)&(-idx));
	}
	//another way (works too)
	// for(int j = 0; j<33; j++){
	// 	if(idx&(1<<j)) {
	// 		if(idx + (1<<j) > n) break; 
	// 		BIT[idx + (1<<j)] += val;
	// 		idx = idx + (1<<j);
	// 	}
	// }
}
int prefix(vector<int> &BIT, int idx){
	int ans = 0;
	while(idx>0){
		ans += BIT[idx];
		idx -= ((idx)&(-idx));
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
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	vector<int> BIT(n+1,0);
	//setup the initial BIT
	for(int i = 1; i<=n; i++){
		update(BIT, i, a[i], n);
	}
	// peek(BIT)
	while(t--){
	int q,i,j;
	cin>>q>>i>>j;
	if(q==1) {
		// pass the difference of new and old values!!
		update(BIT, i, j - a[i], n);
		a[i] = j;
	}
	else cout<<prefix(BIT, j) - prefix(BIT, i-1)<<"\n";
}
}