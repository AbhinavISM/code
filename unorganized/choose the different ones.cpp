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
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n);
	vector<bool> fa(1000001,false);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		fa[item] = true;
	}
	vector<bool> fb(1000001,false);
	vector<int> b(m);
	for(int i = 0; i<m; i++){
		int item;
		cin>>item;
		b[i] = item;
		fb[item] = true;
	}
	int cnta = 0;
	int cntb = 0;
	bool flag = true;
	for(int i = 1; i<=k; i++){
		if(!(fa[i]||fb[i])){
			flag = false;
			break;
		} else if(fa[i]&&(!fb[i])){
			cnta++;
		} else if((!fa[i])&&(fb[i])){
			cntb++;
		}
	}
	if(cnta<=(k/2)&&cntb<=(k/2)&&flag){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}