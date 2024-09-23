#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
struct parabola {
	int a;
	int b;
	int c;
};
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int> k(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>k[i];
	}
	vector<parabola> pb(m, parabola());
	for(int i = 0; i<m; i++){
		int a,b,c;
		cin>>pb[i].a>>pb[i].b>>pb[i].c;
	}
	sort(k.begin(), k.end());

	for(int i = 0; i<m; i++){
		auto it = lower_bound(k.begin(), k.end(), pb[i].b);
		if(it==k.end()) {
			it--;
		}
		if((pb[i].b - *it)*(pb[i].b - *it) - 4*pb[i].a*pb[i].c < 0) {
			cout<<"YES\n";
			cout<<*it<<"\n";
			continue;
		}
		if(it!=k.begin()){
			it--;
			if((pb[i].b - *it)*(pb[i].b - *it) - 4*pb[i].a*pb[i].c < 0) {
				cout<<"YES\n";
				cout<<*it<<"\n";
				continue;
			}
		}
		cout<<"NO\n";
	}
}
	return 0;
}