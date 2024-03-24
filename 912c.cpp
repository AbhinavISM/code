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
	int sum = array[n-1];
	vector<bool> inc(n,false);
	for(int i = n-2; i>=0; i--){
		if(sum>=0){
			inc[i+1] = true;
		}
		sum += array[i];
	}
	int ans = 0;
	int factor = 1;
	for(int i = 0; i<n; i++){
		if(inc[i]){
			factor++;
		}
		ans += factor*array[i];
	}
	cout<<ans<<"\n";
}
	return 0;
}