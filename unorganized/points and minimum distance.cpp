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
	vector<int> array(2*n);
	for(int i = 0; i<2*n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	sort(array.begin(), array.end());
	int ans = 0;
	for(int i = 1; i<n; i++){
		ans += array[i] - array[i-1];
	}
	for(int i = n+1; i<2*n; i++){
		ans += array[i] - array[i-1];
	}
	cout<<ans<<"\n";
	for(int i = 0; i<n; i++){
		cout<<array[i]<<" "<<array[n+i]<<"\n";
	}
}
	return 0;
}