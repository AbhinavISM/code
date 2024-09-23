#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(int k = 0; k<v.size(); k++) cout<<v[k]<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	vector<int> form(n,0);
	for(int i = 0; i<n; i++){
		form[i] = (n-i);
	}
	peek(form)
	int cnt = 1;
	vector<int> ans(n,-1);
	while(k>0){
		auto ub = upper_bound(form.begin(), form.end(), k-((cnt)*(cnt-1))/2);
		ub--;
		int i = ub-form.begin();
		ans[i] = 1000;
		k-=(i+1);
	}
	peek(ans)
}
	return 0;
}