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
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		sum += item;
	}
	int each = sum/n;
	int plus = 0;
	bool good = true;
	for(int i = 0; i<n; i++){
		if(a[i]>each){
			plus += (a[i]-each);
		} else {
			plus -= (each-a[i]);
		}
		if(plus<0){
			good = false;
			break;
		}
	}
	if(plus!=0){
		good = false;
	}
	if(good){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}