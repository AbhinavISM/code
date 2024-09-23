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
	vector<int> array(n);
	int mini = INT_MAX;
	int maxi = INT_MIN;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		if(mini>item){
			mini = item;
		}
		if(maxi<item){
			maxi = item;
		}
	}
	int ans = 0;
	vector<int> ansvec;
	while(mini!=maxi){
		ans += 1;
		if(ans<=n){
			ansvec.push_back(maxi + 1);
		}
		mini = (mini + maxi + 1)/2;
	}
	cout<<ans<<"\n";
	if(ans<=n){
		for(int i : ansvec){
			cout<<i<<" ";
		}
		cout<<"\n";
	}
}
	return 0;
}