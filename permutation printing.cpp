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
	int n;
	cin>>n;
	vector<int> ans(n);
	int val = 0;
	for(int i = 0; i<n; i+=2){
		if(i==n-1){
			ans[i] = (n+1)/2;
			break;
		}
		ans[i] = val+1;
		ans[i+1] = (n-val);
		val++;
	}
	peek(ans)
}
	return 0;
}