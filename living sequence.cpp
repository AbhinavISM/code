#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x;cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int k;
	cin>>k;
	vector<int> ans;
	while(k>0){
		ans.push_back(k%9);
		k/=9;
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i<ans.size(); i++){
		if(ans[i]>=4){
			ans[i]++;
		}
	}
	peek(ans)
}
	return 0;
}