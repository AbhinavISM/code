#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x;cout<<"\n";
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
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	map<int, set<char>> m;
	m[0] = set<char>();
	for(int i = 0; i<26; i++){
		m[0].insert((97 + i));
	}
	vector<char> ans;
	for(int i = 0; i<n; i++){
		char take = *(m[a[i]].begin());
		m[a[i]].erase(m[a[i]].begin());
		ans.push_back(take);
		m[a[i] + 1].insert(take);
	}
	peek(ans)
}
	return 0;
}