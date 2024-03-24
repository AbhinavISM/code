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
	int c;
	cin>>c;
	vector<int> stalls(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		stalls[i] = item;
	}
	sort(stalls.begin(), stalls.end());
	int lo = 1;
	int hi = 1000000000;
	int ans = -1;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int count = 1;
		// cout<<mid<<" ";
		int last = 0;
		for(int i = 1; i<n; i++){
			if(stalls[i]-stalls[last]>=mid){
				count++;
				last = i;
			}
		}
		// if(mid==3){
		// 	cout<<count;
		// }
		if(count>=c){
			ans = max(ans,mid);
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}