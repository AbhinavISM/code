#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
		a[i]--;
	}
	vector<int> b(n);
	for(int i = 0; i<n; i++){
		cin>>b[i];
		b[i]--;
	}
	vector<bool> vis(n,false);
	vector<bool> fined(n,false);
	int j = 0;
	for(int i = 0; i<n; i++){
		if(vis[a[i]]){
			continue;
		}
		while(a[i]!=b[j]){
			vis[b[j]] = true;
			fined[b[j]] = true;
			j++;
		}
		j++;
		vis[a[i]] = true;
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(fined[i]) ans++;
	}
	cout<<ans;
}