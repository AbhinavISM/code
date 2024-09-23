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
	vector<vector<int>> precomp(n+1, vector<int>(32,0));
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		for(int j = 0; j<32; j++){
			precomp[i][31-j] = precomp[i-1][31-j]+item%2;
			item /= 2;
		}
	}
	int q;
	cin>>q;
	while(q--){
		int l;
		cin>>l;
		int k;
		cin>>k;
		// cout<<"query aayi\n";
		int hi = n;
		int lo = l;
		int ans = INT_MIN;
		while(hi>=lo){
			int mid = lo + (hi-lo)/2;
			vector<int> rangeAnd(32,0);
			for(int i = 0; i<32; i++){
				if(precomp[mid][i] - precomp[l-1][i] == mid-l+1){
					rangeAnd[31-i] = 1;
				}
			}
			int rangeAndNum = 0;
			int factor = 1;
			for(int a : rangeAnd){
				rangeAndNum += a*factor;
				factor*=2;
			}
			if(rangeAndNum>=k){
				ans = max(ans, mid);
				lo = mid+1;
			} else {
				hi = mid-1;
			}
		}
		if(ans==INT_MIN){
			cout<<-1<<" ";
		} else {
			cout<<ans<<" ";
		}
	}
	cout<<"\n";
}
	return 0;
}