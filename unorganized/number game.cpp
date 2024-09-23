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
	multiset<int> s;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		s.insert(item);
	}
	int ans = 0;
	for(int k = 1; k<=n; k++){
		multiset<int> ts = s;
		int i = 1;
		for(; i<=k&&s.size()!=0; i++){
			auto lb = lower_bound(ts.begin(), ts.end(), k-i+1);
			// if(k==2&&t==n)cout<<(*lb)<<" "<<k-i+1<<" ";
			if(lb==ts.begin()&&(*lb)>k-i+1){break;}
			else if((lb!=ts.begin()&&(*lb)>k-i+1)||lb==ts.end()) {lb--;}
			ts.erase(lb);
			if(ts.size()!=0){
				int val = *(ts.begin());
				// if(k==2&&t==n)cout<<val<<"\n";
				ts.erase(ts.begin());
				ts.insert(val+k-i+1);
			}
			// if(k==2&&t==n){
			// 	for(int a : ts){
			// 		cout<<a<<" ";
			// 	}
			// }
		}
		// if(k==2)cout<<i<<" ";
		if(i==k+1){
			ans = k;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}