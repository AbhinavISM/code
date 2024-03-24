#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int> l(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		l[i] = item;
	}
	multiset<int> r;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		r.insert(item);
	}
	vector<int> c(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		c[i] = item;
	}
	sort(l.begin(), l.end(), greater<int>());
	sort(c.begin(), c.end(), greater<int>());
	vector<int> diff;
	for(int i = 0; i<n; i++){
		auto it = r.lower_bound(l[i]);
		diff.push_back((*it) - l[i]);
		r.erase(it);
	}
	int ans = 0;
	sort(diff.begin(), diff.end());
	for(int i = 0; i<n; i++){
		ans += diff[i]*c[i];
	}
	cout<<ans<<"\n";
}
	return 0;
}