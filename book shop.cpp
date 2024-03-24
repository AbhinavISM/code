#include<bits/stdc++.h>
// #define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int x;
	cin>>x;
	vector<int> price(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		price[i] = item;
	}
	vector<int> pages(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		pages[i] = item;
	}
	vector<vector<int>> dp(n+1, vector<int>(x+1,0));
	for(int i = n-1; i>=0; i--){
		for(int j = 1; j<=x; j++){
			int a = 0;
			int b = 0;
			if(j-price[i]>=0){
				a = dp[i+1][j-price[i]] + pages[i];
			}
			b = dp[i+1][j];
			dp[i][j] = max(a,b);
		}
	}
	cout<<dp[0][x];
	return 0;
}