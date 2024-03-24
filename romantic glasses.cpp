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
	for(int i = 1; i<n; i++){
		if(i%2==0) a[i] = a[i] + a[i-1];
		else a[i] = a[i-1] - a[i];
	}
	bool ans = false;
	multiset<int> b;
	for(int i = 0; i<n; i++){
		b.insert(a[i]);
		if(b.count(a[i])>=2||a[i]==0){
			ans = true;
			break;
		}
	}
	if(ans){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}