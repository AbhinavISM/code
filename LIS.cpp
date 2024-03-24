#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<int> dp(n,1);

	//O(n^2)
	// for(int i = 1; i<n; i++){
	// 	for(int j = 0; j<i; j++){
	// 		if(array[i]>array[j]&&dp[i]<=dp[j]){
	// 			dp[i] = dp[j]+1;
	// 		}
	// 	}
	// }
	// cout<<*max_element(dp.begin(),dp.end());

	//o(nlogn)
	

	return 0;
}