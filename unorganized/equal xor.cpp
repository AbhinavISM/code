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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	vector<int> fa(n+1,0);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		fa[item]++;
	}
	vector<int> b(n);
	vector<int> fb(n+1,0);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		b[i] = item;
		fb[item]++;
	}
	vector<int> l;
	vector<int> r;
	for(int i = 1; i<=n&&l.size()<2*k; i++){
		if(fa[i]==fb[i]){
			l.push_back(i);
			r.push_back(i);
		}
	}
	if(l.size()%2==1&&l.size()>0){
		l.erase(--l.end());
		r.erase(--r.end());
	}
	for(int i = 1; i<=n&&l.size()<2*k; i++){
		if(fa[i]==2){
			l.push_back(i);
			l.push_back(i);
		}
	}
	for(int i = 1; i<=n&&r.size()<2*k; i++){
		if(fb[i]==2){
			r.push_back(i);
			r.push_back(i);
		}
	}
	peek(l)
	peek(r)

}
	return 0;
}