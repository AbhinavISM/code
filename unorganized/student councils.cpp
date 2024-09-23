#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int k;
	cin>>k;
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	int hi = 1e12;
	int lo = 0;
	int ans = 0;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int sum = 0;
		for(int i = 0; i<n; i++){
			sum += min(mid,array[i]);
		}
		if(sum>=mid*k){
			ans = mid;
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}