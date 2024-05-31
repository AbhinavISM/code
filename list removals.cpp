#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void update(vector<int> &BIT, int idx, int val, int n){
	while(idx<=n){
		BIT[idx] += val;
		idx += ((idx)&(-idx));
	}
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
	int t = n;
	vector<int> a(n+1,0);
	vector<int> BIT(n+1,0);
	for(int i = 1; i<=n; i++){
		update(BIT, i, 1, n);
		cin>>a[i];
	}
	while(t--){
	int p;
	cin>>p;
	int lo = 1;
	int hi = n;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		if(prefix(BIT, mid)==p&&a[mid]!=0){
			cout<<a[mid]<<" ";
			a[mid] = 0;
			update(BIT, mid, -1, n);
			break;
		} else if(prefix(BIT, mid)>=p){
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
}
	return 0;
}