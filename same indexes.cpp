#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
// vector<int> factorials(200001);
// void precompfact(){
// 	factorials[0] = 1;
// 	for(int i = 1; i<200001; i++){
// 		factorials[i] = factorials[i-1]*i;
// 	}
// }
// int ncr(int n, int r){
// 	return(factorials[n]/(factorials[n-r] * factorials[r]));
// }
int32_t main(){
	fast_io;
	// precompfact();
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	map<int,int> mymap;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		mymap[item-i]++;
	}
	int ans = 0;
	for(auto it : mymap){
		ans += ((it.second)*(it.second-1))/2;
	}
	cout<<ans<<"\n";
}
	return 0;
}