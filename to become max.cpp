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
	int k;
	cin>>k;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	int ans = 0;
	for(int i = n-1; i>0; i--){
		vector<int> ta = a;
		int maxi = a[i];
		int tk = k;
		for(int j = i-1; j>=0; j--){
			if(ta[j]<=ta[j+1]){
				if(ta[j+1]-ta[j]+1<=tk){
					tk-=ta[j+1]-ta[j]+1;
					ta[j] = ta[j+1] + 1;	
				}
			}
			maxi = max(maxi, ta[j]);
		}
		ans = max(ans, maxi);
	}
	cout<<ans<<"\n";
}
	return 0;
}