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
	vector<bool> ispresent(n+1, false);
	ispresent[0] = true;
	int ans = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(!ispresent[item-1]){
			ans++;
		}
		ispresent[item] = true;
	}
	cout<<ans<<"\n";
}
	return 0;
}