#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int m;
	cin>>m;
	// vector<pair<int, int>> vp;
	vector<int> s;
	vector<int> e;
	vector<int> s1;
	vector<int> e1;
	for(int i = 0; i<n; i++){
		int a,b;
		cin>>a>>b;
		// vp.push_back({a,b});
		if(a!=1&&b!=1){
			s.push_back(a);
			e.push_back(b);
		}
		if(a!=m&&b!=m){
			s1.push_back(a);
			e1.push_back(b);			
		}
	}
	sort(s.begin(), s.end());
	sort(e.begin(), e.end());
	sort(s1.begin(), s1.end());
	sort(e1.begin(), e1.end());
	int ans = 0;
	for(int i = 0; i<s.size(); i++){
		auto ub = upper_bound(s.begin(), s.end(), s[i]);
		int num_of_s_less_or_equal = (ub-s.begin());
		// cout<<num_of_s_less_or_equal<<" ";
		auto lb = lower_bound(e.begin(), e.end(), s[i]);
		int num_of_e_less = (lb-e.begin());
		// cout<<(*lb)<<" ";
		int val = num_of_s_less_or_equal - num_of_e_less;
		// cout<<val<<" ";
		ans = max(ans, val);
	}
	for(int i = 0; i<s1.size(); i++){
		auto ub = upper_bound(s1.begin(), s1.end(), s1[i]);
		int num_of_s_less_or_equal = (ub-s1.begin());
		auto lb = lower_bound(e1.begin(), e1.end(), s1[i]);
		int num_of_e_less = (lb-e1.begin());
		int val = num_of_s_less_or_equal - num_of_e_less;
		ans = max(ans, val);
	}
	cout<<ans<<"\n";
}
	return 0;
}