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
	vector<vector<bool>> array(n,vector<bool>());
	vector<vector<bool>> marked(n,vector<bool>());
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			int item;
			cin>>item;
			array[i].push_back(item);
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(array[i][j]){
				array[i][j] = 0;
				
			}
		}
	}

}
	return 0;
}