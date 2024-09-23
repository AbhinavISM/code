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
	int x;
	cin>>x;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	sort(array.begin(), array.end());
	vector<int> prefix(n,0);
	prefix[0] = array[0];
	for(int i = 1;  i<n; i++){
		prefix[i] = prefix[i-1] + array[i];
	}
	int ans = 0;
	int lastdays = 0;
	for(int i = n-1; i>=0 ;i--){
		int days = (x-prefix[i] + i + 1)/(i+1);
		// cout<<days<<" ";
		if(days>0&&lastdays>=0){
			ans += (days-lastdays)*(i+1);
			lastdays = days;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}