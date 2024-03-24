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
	int n,a,b;
	cin>>n>>a>>b;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<int> prefix(n,0);
	prefix[0] = array[0];
	for(int i = 1; i<n; i++){
		prefix[i] += (prefix[i-1]+array[i]);
	}
	int ans = prefix[n-1]*b;
	for(int i = 0; i<n; i++){
		ans = min(ans, (array[i])*b + (array[i])*a + (prefix[n-1]-prefix[i]-(n-i-1)*array[i])*b);
	}
	cout<<ans<<"\n";
}
	return 0;
}