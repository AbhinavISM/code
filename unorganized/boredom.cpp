#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n);
	vector<int> f(100001,0);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		f[array[i]]++;
	}
	vector<int> dp(100001,0);
	for(int i = 1; i<=100000; i++){
		int a = dp[i-1];
		int b = f[i]*i;
		if(i-2>0) {b += dp[i-2];}
		dp[i] = max(a,b);
	}
	cout<<dp[100000];
}