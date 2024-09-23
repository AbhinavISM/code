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
	int sum = 0;
	bool yes = false;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		sum += item;
		if(item%3==1){
			yes = true;
		}
	}
	if(sum%3==0){
		cout<<0<<"\n";
	} else if(sum%3==2){
		cout<<1<<"\n";
	} else {
		if(yes){
			cout<<1<<"\n";
		} else {
			cout<<2<<"\n";
		}
	}
}
	return 0;
}