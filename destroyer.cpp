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
	vector<int> f(101,0);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		f[item]++;
	}
	int maxi = 0;
	bool ans = true;
	for(int i = 99; i>=0; i--){
		maxi = max(maxi, f[i]);
		if(f[i]<maxi){
			ans = false;
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