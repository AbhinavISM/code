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
	vector<vector<char>> matrix(n, vector<char>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin>>matrix[i][j];
		}
	}
	int jump = n;
	int ops = 0;
	for(int i = 0; i<n/2; i++){
		vector<char> final;
		for(int j = i; j<n-i; j++){
			final.push_back(matrix[i][j]);
		}
		for(int j = i; j<n-i; j++){
			final.push_back(matrix[j][n-i-1]);
		}
		for(int j = n-i-1; j>=i; j--){
			final.push_back(matrix[n-i-1][j]);
		}
		for(int j = i; j<n-i; j++){
			final.push_back(matrix[j][i]);
		}
		char maxi = '0';
		for(int j = 0; j<n-2*i-1; j++){
			for(int k = 0; k<4; k++){
				maxi = max(final[j+k*(n-2*i)], maxi);
				// cout<<final[j+k*(n-2*i)]<<" ";
			}
			for(int k = 0; k<4; k++){
				// if(j!=n-2*i-1){
				ops+=(maxi-final[j+k*(n-2*i)]);
				// cout<<(maxi-final[j+k*(n-2*i)])<<" ";
				// }
			}
		}
		for(char f : final){
			cout<<f<<" ";
		}
		cout<<"\n";
		cout<<"\n";
		cout<<"\n";

	}
	// cout<<ops<<"\n";
	// cout<<"\n";
}
	return 0;
}