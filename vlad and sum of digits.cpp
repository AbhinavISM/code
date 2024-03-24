#include<bits/stdc++.h>
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	int n = 200001;
	vector<int> a(200001,0);
	for(int i = 1; i<=n; i++){
		a[i] = i;
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		int sum = 0;
		while(a[i]!=0){
			sum += a[i]%10;
			a[i] = a[i]/10;
		}
		ans += sum;
		a[i] = ans;
	}
	while(t--){
	int x;
	cin>>x;
	cout<<a[x]<<"\n";
}
	return 0;
}