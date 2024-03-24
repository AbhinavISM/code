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
	vector<int> a;
	set<int> done;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(done.find(item)==done.end()) {a.push_back(item);done.insert(item);}
	}
	sort(a.begin(), a.end());
	
}
	return 0;
}