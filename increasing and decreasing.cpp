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
	int x;
	cin>>x;
	int y;
	cin>>y;
	int n;
	cin>>n;
	vector<int> ans(n);
	int c = 1;
	ans[n-1] = y;
	for(int i = n-2; i>=0; i--){
		ans[i] = ans[i+1] - c;
		c++;
	}
	if(ans[0]>=x){
		bool done = true;
		for(int a : ans){
			if(done){
				cout<<x<<" ";
				done = false;
			} else {
			cout<<a<<" ";				
			}
		}
	} else {
		cout<<"-1";
	}
	cout<<"\n";
}
	return 0;
}