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
	int n,m,x;
	cin>>n>>m>>x;
	int throws = m;
	set<int> hasball;
	hasball.insert(x);
	while(throws--){
		int len;
		char dir;
		cin>>len;
		cin>>dir;
		set<int> hasnewball;
		for(int i : hasball){
			if(dir=='0'){
				int gullu = i + len;
				if(gullu > n){
					gullu -= n;
				}
				hasnewball.insert(gullu);
			} else if(dir=='1'){
				int gullu = i + (n-len);
				if(gullu > n){
					gullu -= n;
				}
				hasnewball.insert(gullu);
			} else {
				int gullu = i + len;
				if(gullu > n){
					gullu -= n;
				}
				hasnewball.insert(gullu);
				gullu = i + (n-len);
				if(gullu > n){
					gullu -= n;
				}
				hasnewball.insert(gullu);
			}
		}
		hasball = hasnewball;
	}
	cout<<hasball.size()<<"\n";
	peek(hasball)
}
	return 0;
}