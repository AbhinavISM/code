#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
void solve(){
	int n;
	cin>>n;
	map<int,int> bitfreq;
	vector<unordered_set<int>> num(n, unordered_set<int>());
	for(int i = 0; i<n; i++){
		int ki;
		cin>>ki;
		for(int j = 0; j<ki; j++){
			int bit;
			cin>>bit;
			num[i].insert(bit);
			bitfreq[bit]++;
		}
	}
	for(int i = 0; i<n; i++){
		bool common = true;
		for(int bit : num[i]){
			if(bitfreq[bit]<=1){
				common = false;
			}
		}
		if(common){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
}
	return 0;
}