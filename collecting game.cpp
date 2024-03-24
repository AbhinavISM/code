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
	vector<pair<int,int>> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = {item,i};
	}
	sort(array.begin(), array.end());
	vector<int> prefix(n,0);
	for(int i = 0; i<n; i++){
		if(i>0){
			prefix[i] = prefix[i-1] + array[i].first;
		} else {
			prefix[i] = array[i].first;
		}
	}
	vector<bool> fool(n,false);
	for(int i = 0; i<n; i++){
		if(i==n-1){
			fool[i] = false;
		}
		else if(prefix[i+1] - prefix[i]>prefix[i]){
			fool[i] = false;
		} else {
			fool[i] = true;
		}
	}
	// for(bool a : fool){
	// 	cout<<a<<" ";
	// }
	// cout<<"\n";
	vector<int> ans(n);
	ans[array[n-1].second] = n-1;
	for(int i = n-2; i>=0; i--){
		if(fool[i] == true){
			ans[array[i].second] = ans[array[i+1].second];
		} else {
			ans[array[i].second] = i;
		}
	}
	for(int a : ans){
		cout<<a<<" ";
	}
	cout<<"\n";
	// vector<int> ans(n);
	// ans[array[n-1].first] = n-1;
	// for(int i = n-2; i>=0; i--){

	// }
}
	return 0;
}