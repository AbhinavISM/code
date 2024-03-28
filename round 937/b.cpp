#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<char> i : v) {for(char j : i){ cout<<j<<"";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<vector<char>> ans(2*n,vector<char>(2*n,'*'));
	for(int i = 0; i<2*n; i++){
		bool hash;
		if((i/2)%2) hash = false;
		else hash = true;
		for(int j = 0; j<2*n; j+=2){
			if(hash) {
				ans[i][j] = '#';
				ans[i][j+1] = '#';
			} else {
				ans[i][j] = '.';
				ans[i][j+1] = '.';
			}
			hash = !hash;
		}
	}
	dpeek(ans)
}
	return 0;
}