#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
bool check(vector<int> &a, int n, int h, int mid){
	int req = 0;
	for(int houses : a){
		req += houses/mid;
		if(houses%mid) req++;
	}
	if(req<=h) return true;
	else return false;
}
int solve(vector<int> a, int n, int h){
	int lo = 0;
	int hi = INT64_MAX;
	int ans = INT64_MAX;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		if(check(a,n,h,mid)){
			ans = min(ans, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return ans;
}
int32_t main(){
	fast_io;
	int n,h;
	cin>>n>>h;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	cout<<solve(a,n,h);
}