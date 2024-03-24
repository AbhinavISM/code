#include<bits/stdc++.h>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define int long long
int32_t main(){
	int mod = 1000000007;
	fast_io;
	int t;
	cin>>t;
	vector<vector<vector<int>>> f(10,vector<vector<int>>(200001, vector<int>(10,0)));
	for(int i = 0; i<10; i++){
		f[i][0][i] = 1;
	}
	for(int k = 0; k<10; k++){
		for(int i = 1; i<=200000; i++){
			f[k][i] = f[k][i-1];
			int tmp = f[k][i][9];
			for(int j = 9; j>=1; j--){
				f[k][i][j] = f[k][i][j-1];
			}
			f[k][i][0] = tmp;
			f[k][i][1] += tmp;
			f[k][i][1]%=mod;
			// if(i==2&&k==9){cout<<f[k][i][9];}
		}
	}
	// cout<<f[0]
	while(t--){
	int n;
	cin>>n;
	int m;
	cin>>m;
	
	int ans = 0;
	vector<int> freq(10,0);
	while(n>0){
		freq[n%10]++;
		n/=10;
	}
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			ans += (((freq[i])*f[i][m][j])%mod);
			ans %= mod;			
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}