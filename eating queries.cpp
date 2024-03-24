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
	int q;
	cin>>q;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	sort(array.begin(), array.end(), greater<int>());
	vector<int> prefix(n);
	prefix[0] = array[0];
	for(int i = 1; i<n; i++){
		prefix[i] = prefix[i-1] + array[i];
	}
	while(q--){
		int x;
		cin>>x;
		auto ans = lower_bound(prefix.begin(), prefix.end(),x);
		if(ans!=prefix.end()){
			cout<<ans-prefix.begin()+1;
		} else {
			cout<<-1;
		}
		cout<<"\n";
	}
}
	return 0;
}