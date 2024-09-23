#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
void solve(){
		int n;
	cin>>n;
	vector<vector<int>> array(n,vector<int>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin>>array[i][j];
		}
	}

	int skp = 0;
	vector<int> ans(n,0);
	for(int i = 0; i<n; i++){
		bool door = true;
		for(int j = 0; j<n; j++){
			if(j==skp){
				continue;
			}
			if(door){
				ans[i] = ans[i]|array[i][j];
				door = false;
			} else {
				ans[i] = ans[i]&array[i][j];
			}
		}
		skp++;
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(i==j){continue;}
			if((ans[i]|ans[j]) != array[i][j]){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
	for(int i = 0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
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