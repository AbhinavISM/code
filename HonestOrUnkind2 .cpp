#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<vector<int>> t(n, vector<int>(15,-1));
	for(int i = 0; i<n; i++){
		int a;
		cin>>a;
		for(int i = 0; i<a; i++){
			int x,y;
			cin>>x>>y;
			t[i][x] = y;
		}
	}
	int ans = 1;
	for(int i = 1; i<(1<<n); i++){
		vector<int> check(15,-1);
		bool possible = true;
		for(int j = 0; j<n; j++){
			if((i>>j)&1){
				check[j] = 1;
				for(int k = 0; k<15; k++){
					if(check[k]==-1){
						check[k] = t[j][k];
					} else if(check[k]!=t[j][k]){
						possible = false;
					}
				}
			}
		}
		bool changed = true;
		while(changed){
			changed = false;
			for(int j = 0; j<15; j++){
				if(check[j]==1){
					for(int k = 0; k<15; k++){
						if(check[k]==-1){
							check[k] = t[j][k];
							changed = true;
						} else if(check[k]!=t[j][k]){
							possible = false;
							changed = true;
						}
					}
				}
			}
		}
	int thisans = 0; 
	if(possible){
		for(int k = 0; k<15; k++){
			if(check[k]==1){
				thisans++;
			}
		}
	}
	ans = max(thisans,ans);	
	}
	cout<<ans;
	return 0;
}