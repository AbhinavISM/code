#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int32_t main(){
	fast_io;
	int t = 1;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n,0);
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		int ans = 0;
		vector<vector<int>> occurences(n+1, vector<int>());
		for(int i = 0; i<n; i++){
			occurences[a[i]].push_back(i);	
		}
		for(auto it : occurences){
			if(it.size()==0) continue;
			ans -= ((it[0])*(it[0]+1))/2;
			ans -= ((n-it.back()-1)*(n-it.back()))/2;
			for(int i = 1; i<it.size(); i++){
				ans -= ((it[i]-it[i-1]-1)*(it[i]-it[i-1]))/2;
			}
			ans += (n*(n+1))/2;
		}
		cout<<ans;
	}
	return 0;
}