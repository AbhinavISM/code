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
	int n,s1,s2;
	cin>>n>>s1>>s2;
	vector<pair<int,int>> r;
	for(int i = 0; i<n; i++){
		int ri;
		cin>>ri;
		r.push_back({ri,i+1});
	}
	sort(r.begin(), r.end(), greater<pair<int,int>>());
	vector<int> a;
	vector<int> b;
	for(int i = 0; i<n; i++){
		int f1 = a.size()+1;
		int f2 = b.size()+1;
		if(f1*s1*r[i].first<f2*s2*r[i].first){
			a.push_back(r[i].second);
		} else if(f1*s1*r[i].first>f2*s2*r[i].first){
			b.push_back(r[i].second);
		} else {
			if(f1>=f2){
				a.push_back(r[i].second);
			} else {
				b.push_back(r[i].second);
			}
		}
	}
	cout<<a.size()<<" ";
	peek(a);
	cout<<b.size()<<" ";
	peek(b);
}
	return 0;
}