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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	vector<int> ans(n);
	ans[0] = a[0];
	int oddcnt = 0;
	int evencnt = 0;
	if(a[0]%2){
		oddcnt++;
	} else {
		evencnt++;
	}
	int sum = a[0];
	for(int i = 1; i<n; i++){
		sum+=a[i];
		if(a[i]%2){
			oddcnt++;
		} else {
			evencnt++;
		}
		int d = oddcnt/3;
		if(oddcnt%3==1){
			d++;
		}
		ans[i] = sum-d;
	}
	peek(ans)
}
	return 0;
}