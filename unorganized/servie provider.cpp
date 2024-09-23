#include<bits/stdc++.h>
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
long long getMaxDiscount(vector<int> discounts, int k){
	int n = discounts.size();
	vector<int> f(31,0);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<31; j++){
			if(discounts[i]&(1<<j)) f[j]++;
		}
	}
	long long ans = 0;
	for(int i = 0; i<n; i++){
		long long tans = 0ll;
		for(int j = 0; j<31; j++){
			if(discounts[i]&(1<<j)) f[j]--;
		}
		int tmp = discounts[i]*(1<<k);
		for(int j = 0; j<31; j++){
			if(f[j]>0)	{
				tans = tans|(1<<j);
			}
		}
		tans = tans|tmp;
		ans = max(ans, tans);
		for(int j = 0; j<31; j++){
			if(discounts[i]&(1<<j)) f[j]++;
		}
	}
	return ans;
}
int32_t main(){
	fast_io;
	int n,k;
	cin>>n>>k;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	cout<<getMaxDiscount(a, k);
}