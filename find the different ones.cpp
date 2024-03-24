#include<bits/stdc++.h>
#define int long long
#define ld long double
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
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	vector<int> pre(n);
	vector<int> lastdiff(n,-1);
	int last = a[0];
	pre[0] = 0;
	for(int i = 1; i<n; i++){
		if(a[i]==last){
			pre[i] = pre[i-1];
			lastdiff[i] = lastdiff[i-1];
		} else {
			lastdiff[i] = i-1;
			last = a[i];
			pre[i] = i;
		}
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		if(pre[l]==pre[r]){
			cout<<-1<<" "<<-1<<"\n";
		} else if(a[l]!=a[r]){
			cout<<r+1<<" "<<l+1<<"\n";
		} else {
			cout<<lastdiff[r]+1<<" "<<l+1<<"\n";
		}
	}
	cout<<"\n";
}
	return 0;
}