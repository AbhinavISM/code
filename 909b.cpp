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
	vector<int> array(n+1,0);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = array[i-1] + item;
	}
	if(n==1){
		cout<<0<<"\n";
		continue;
	}
	int ans = INT64_MIN;
	for(int k = 1; k*k<=n; k++){
		if(n%k==0){
			int mini = INT64_MAX;
			int maxi = INT64_MIN;
			for(int j = k; j<=n; j+=k){
				mini = min(mini, array[j] - array[j-k]);
				maxi = max(maxi, array[j] - array[j-k]);
			}
			ans = max(ans, maxi-mini);
			if(k!=1){
				mini = INT64_MAX;
				maxi = INT64_MIN;
				for(int j = n/k; j<=n; j+=(n/k)){
					mini = min(mini, array[j] - array[j-(n/k)]);
					maxi = max(maxi, array[j] - array[j-(n/k)]);
				}
				ans = max(ans, maxi-mini);
			}
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}