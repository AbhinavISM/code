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
	int miniwin = INT_MAX;
	int ans = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(item>mini&&item<miniwin){
			miniwin = item;
			ans++;
		}
		if(item<mini){
			mini = item;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}