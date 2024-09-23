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
	int n,c,d;
	cin>>n>>c>>d;
	multiset<int> ms;
	for(int i = 0; i<n*n; i++){
		int a;
		cin>>a;
		ms.insert(a);
	}
	int a11 = *ms.begin();
	// cout<<a11<<"\n";
	vector<vector<int>> mat(n,vector<int>(n));
	mat[0][0] = a11;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(i==0&&j==0){continue;}
			if(j==0) {mat[i][j] = mat[i-1][j] + c; continue;}
			mat[i][j] = mat[i][j-1] + d;
		}
	}
	dpeek(mat)
	bool good = true;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(ms.find(mat[i][j])==ms.end()) {
				good = false;
				break;
			}
			ms.erase(ms.find(mat[i][j]));
		}
	}
	if(good){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}