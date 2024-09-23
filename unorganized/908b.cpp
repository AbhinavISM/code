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
	vector<vector<int>> array(101,vector<int>());
	vector<int> ans(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[item].push_back(i);
	}
	int repcnt = 0;
	for(int i = 0; i<101; i++){
		if(array[i].size()>=2){repcnt++;}
	}
	if(repcnt<2){
		cout<<"-1\n";
	} else {
		bool first = true;
		for(int i = 0; i<101; i++){
			if(array[i].size()==1){
				ans[array[i][0]] = 1;
			} else if(array[i].size()>=2&&first==true) {
				int j;
				for(j = 0; j<array[i].size(); j++){
					ans[array[i][j]] = 1;
				}
				ans[array[i][array[i].size()-1]] = 2;
				first = false;
			} else if(array[i].size()>=2){
				int j;
				for(j = 0; j<array[i].size(); j++){
					ans[array[i][j]] = 1;
				}
				ans[array[i][array[i].size()-1]] = 3;
			}
		}
		for(int i = 0; i<n; i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	
}
	return 0;
}