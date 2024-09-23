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
	int first = a[0];
	int firstcnt = 0;
	for(int i = 0; i<n; i++){
		if(a[i]==first){
			firstcnt++;
		} else {
			break;
		}
	}
	int last = a[n-1];
	int lastcnt = 0;
	for(int i = n-1; i>=0; i--){
		if(a[i]==last){
			lastcnt++;
		} else {
			break;
		}
	}
	if(first==last){
		if(firstcnt==n){
			cout<<0<<"\n";
		} else {
			cout<<(n-lastcnt-firstcnt)<<"\n";
		}
	} else {
		cout<<(n-max(lastcnt, firstcnt))<<"\n";
	}
}
	return 0;
}