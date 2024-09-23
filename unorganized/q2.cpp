#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
int solve(int n , vector<int> a){
	int minf = INT_MAX;
	map<int,int> ff;
	for(int i = 0; i<n; i++){
		ff[a[i]]++;
	}
	for(auto it : ff){
		minf = min(minf, it.second);
	}
	cout<<minf<<" ";
	int i = 0; int j = 0;
	map<int,int> f;
	int ans = 0;
	while(j<n){
		f[a[j]]++;
		while(f[a[j]]>minf){
			f[a[i]]--;
			i++;
		}
		int ans = max(ans, j-i+1);
		j++;
	}
	return ans;
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	cout<<solve(n,a);
}