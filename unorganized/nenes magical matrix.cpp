#include<bits/stdc++.h>
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<vector<int>> ans(n,vector<int>(n,0));
	bool row = true;
	bool again = true;
	int ops = 0;
	vector<vector<int>> truans;
	while(again&&ops<n*n){
		again = false;
		if(row){
			for(int i = 0; i<n; i++){

				int sum = 0;
				bool same = true;
				int tothis = 1;
				for(int j = 0; j<n; j++){
					sum += ans[i][j];
					if(ans[i][j]!=tothis) same = false;
					tothis++;
				}
				if(sum>n*(n+1)/2||same){
					break;
				}

				again = true;
				int per = 1;
				truans.push_back(vector<int>());
				(*truans.rbegin()).push_back(1);
				(*truans.rbegin()).push_back(i+1);
				// cout<<1<<" ";
				// cout<<i+1<<" ";
				ops++;
				for(int j = 0; j<n; j++){
					ans[i][j] = per;
					(*truans.rbegin()).push_back(ans[i][j]);
					// cout<<ans[i][j]<<" ";
					per++;
				}
				// cout<<"\n";
				row = false;
			}
		} else {
			for(int j = 0; j<n; j++){

				int sum = 0;
				bool same = true;
				int tothis = 1;
				for(int i = 0; i<n; i++){
					sum += ans[i][j];
					if(ans[i][j]!=tothis) same = false;
					tothis++;
				}
				if(sum>n*(n+1)/2||same){
					break;
				}

				again = true;
				int per = 1;
				truans.push_back(vector<int>());
				(*truans.rbegin()).push_back(2);
				(*truans.rbegin()).push_back(j+1);
				// cout<<2<<" ";
				// cout<<j+1<<" ";
				ops++;
				for(int i = 0; i<n; i++){
					ans[i][j] = per;
					(*truans.rbegin()).push_back(ans[i][j]);
					// cout<<ans[i][j]<<" ";
					per++;
				}
				// cout<<"\n";
				row = true;
			}
		}
	// dpeek(ans)
	// cout<<"\n";
	}
	int maxsum = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			maxsum += ans[i][j];
		}
	}
	cout<<maxsum<<" "<<ops<<"\n";
	dpeek(truans)
}
	return 0;
}