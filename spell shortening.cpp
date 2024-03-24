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
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	if(n==1||n==2){
	    cout<<-1<<"\n";
	    continue;
	}
	map<int,int> ans;
	for(int i = 2; i<=n; i+=2){
	    ans[i] = i;
	}
	vector<int> odds;
	for(int i = 1; i<=n; i+=2){
	    odds.push_back(i);
	}
	reverse(odds.begin(), odds.end());
	int j = 0;
	for(int i = 1; i<=n; i+=2){
	    ans[i] = odds[j];
	    j++;
	}
	for(int i=0; i<n; i++){
	    cout<<ans[a[i]]<<" ";
	}
	cout<<"\n";
}
	return 0;
}