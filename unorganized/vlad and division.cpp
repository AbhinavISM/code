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
	multiset<int> a;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a.insert(item);
	}
	int ans = 0;
	while(a.size()>0){
		int f = *(a.begin());
		a.erase(a.begin());
		for(int j = 0; j<31; j++){
			f = f^(1<<j);
		}
		if(a.find(f) != a.end()){
			a.erase(a.find(f));
		}
		ans++;
	}
	cout<<ans<<"\n";
}
	return 0;
}