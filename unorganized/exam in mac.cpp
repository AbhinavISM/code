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
	int n,c;
	cin>>n>>c;
	set<int> s;
	int evencnt = 0;
	int oddcnt = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		s.insert(item);
	}
	int ans = (c+1)*(c+1);
	ans -= ((c)*(c+1))/2;
	for(int i : s){
		if(i%2){
			oddcnt++;
		} else {
			evencnt++;
		}
		ans -= (i/2);
		ans -= (c - i + 1);
	}
	ans += ((oddcnt)*(oddcnt-1))/2;
	ans += ((evencnt)*(evencnt-1))/2;
	cout<<ans<<"\n";
}
	return 0;
}