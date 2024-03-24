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
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	string s;
	cin>>s;
	int hi = n-1;
	int lo = 0;
	for(int i = 0; i<n&&hi!=lo; i++){
		if(s[i]=='L'){
			lo++;
		} else {
			hi--;
		}
	}
	vector<int> ans;
	int pro = a[hi];
	pro = pro%m;
	ans.push_back(pro);
	for(int i = n-2; i>=0; i--){
		if(s[i]=='L'){
			lo--;
			pro*=a[lo];
		} else {
			hi++;
			pro*=a[hi];
		}
		pro = pro%m;
		ans.push_back(pro);
	}
	reverse(ans.begin(), ans.end());
	peek(ans)
	cout<<"\n";
}
	return 0;
}