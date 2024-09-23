#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	bool huh = true;
	for(int i = 1; i<n; i++){
		if(a[i]!=a[i-1]) huh = false;
	}
	if(huh) {
		cout<<-1<<"\n";
		continue;
	}
	if(a[0]!=a[n-1]){
		cout<<0<<"\n";
		continue;
	}
	int ans = INT_MAX;
	int i = 0;
	int curr = 0;
	while(i<n){
		if(a[i]==a[0]){
			curr++;
		} else {
			ans = min(curr, ans);
			curr = 0;
		}
		i++;
	}
	ans = min(curr, ans);
	cout<<ans<<"\n";
}
	return 0;
}