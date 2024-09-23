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
	vector<string> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	set<int> lastcnt;
	bool sq = false;
	for(int i = 0; i<n; i++){
		int cnt = 0;
		for(int j = 0; j<n; j++){
			if(a[i][j]=='1'){
				cnt++;
			}
		}
		if(cnt!=0){
			if(lastcnt.find(cnt)!=lastcnt.end()){
				sq = true;
				break;
			} else {
				lastcnt.insert(cnt);
			}
		}
		
	}
	if(sq) cout<<"SQUARE\n";
	else cout<<"TRIANGLE\n";

}
	return 0;
}