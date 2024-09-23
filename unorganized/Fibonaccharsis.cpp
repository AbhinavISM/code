#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	if(k>=30){
		cout<<0<<"\n";
		continue;
	}
	int ans = 0;
	vector<int> fib(k+1,0);
	fib[k] = n;
	for(int i = n; i>=0; i--){
		fib[k-1] = i;
		bool good = true;
		for(int j = k-2; j>=1; j--){
			fib[j] = fib[j+2] - fib[j+1];
			if(fib[j]<0){
				good = false;
			}
			if(fib[j]>fib[j+1]){
				good = false;
			}
		}
		if(fib[1]==0&&fib[2]==0){
			good = false;
		}
		vector<int> tfib(k+1,0);
		tfib[1] = fib[1];
		tfib[2] = fib[2];
		for(int j = 3; j<=k; j++){
			tfib[j] = tfib[j-1] + tfib[j-2];
		}
		bool same = true;
		for(int i = 1; i<=k; i++){
			if(tfib[i]!=fib[i]){
				good = false;
			}
		}
		if(good){
			ans++;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}