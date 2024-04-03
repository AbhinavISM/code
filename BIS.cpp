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
	string a;
	cin>>a;
	int oo = 0;
	int oO = 0;
	int Oo = 0;
	int OO = 0;
	for(int i = 0; i<n; i+=2){
		if(a[i]=='0'&&a[i+1]=='0') oo++;
		else if(a[i]=='0'&&a[i+1]=='1') oO++;
		else if(a[i]=='1'&&a[i+1]=='0') Oo++;
		else if(a[i]=='1'&&a[i+1]=='1') OO++;
	}
	int ans = 0;
	ans += oo*2;
	if(oO>=1){
		ans += 2;
	}
	ans += OO*2;
	if(Oo>=1){
		ans += 1;
	}
	cout<<ans<<"\n";
}
	return 0;
}