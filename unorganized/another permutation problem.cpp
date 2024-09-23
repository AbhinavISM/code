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
	vector<int> a(n);
	int ans = 0;
	for(int i = 1; i<=n*n; i++){
		set<int> taken;
		for(int j = 1; j<=n; j++){
			taken.insert(j);
		}
		int sum = 0;
		int maxi = 0;
		bool good = true;
		for (int j = n; j >=1; j--)
		{
			if(i/j==0){
				good = false;
				break;
			}
			auto lb = taken.lower_bound(i/j);
			if((*lb)==(i/j)){
				sum += j*(*lb);
				maxi = max(maxi,j*(*lb));
				taken.erase(lb);
			} else if(lb!=taken.begin()){
				lb--;
				sum += j*(*lb);
				maxi = max(maxi,j*(*lb));
				taken.erase(lb);
			} else {
				good = false;
				break;
			}
		}
		if(good){
			ans = max(ans, sum-maxi);
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}