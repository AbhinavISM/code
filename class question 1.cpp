#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	// cin>>t;
	while(t--){
	int n;
	// cin>>n;
	vector<int> l(n);
	vector<int> r(n);
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	for(int i = 0; i<n; i++){
		int li = l[i];
		int ri = r[i];
		auto a = upper_bound(r.begin(), r.end(), li);
		int num1 = (int)(a-r.begin());
		int b = lower_bound() 
	}
}
	return 0;
}