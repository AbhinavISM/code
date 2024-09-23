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
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	int ans = 0;
	int zero = 0;
	int ans1 = 0;
	int firstzero = INT_MAX;
	int lastone = INT_MIN;
	for(int i = n-1; i>=0; i--){
		if(array[i]==0){
			firstzero = min(i,firstzero);
			zero++;
		} else {
			ans1 += zero;
			lastone = max(i, lastone);
		}
	}
	// cout<<firstzero<<" "<<lastone<<" ";
	ans = max(ans,ans1);
	if(firstzero!=INT_MAX){
		array[firstzero] = 1;
		zero = 0;
		int ans2 = 0;
		for(int i = n-1; i>=0; i--){
			if(array[i]==0){
				zero++;
			} else {
				ans2 += zero;
			}
		}
		ans = max(ans,ans2);
		array[firstzero] = 0;
	}
	if(lastone!=INT_MIN){
		array[lastone] = 0;
		zero = 0;
		int ans3 = 0;
		for(int i = n-1; i>=0; i--){
			if(array[i]==0){
				zero++;
			} else {
				ans3 += zero;
			}
		}
		ans = max(ans,ans3);
		array[lastone] = 1;
	}
	cout<<ans<<"\n";
}
	return 0;
}