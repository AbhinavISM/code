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
	set<int> s;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		s.insert(item);
	}
	int mex = 0;
	int cnt = 0;
	for(int e : s){
		if(e>mex){
			break;
		} else if(e==mex){
			mex++;
		}
	}
	int lo = INT64_MAX;
	int hi = INT64_MIN;
	for(int i = 0; i<n; i++){
		if(a[i]==mex+1){
			lo = min(lo,i);
			hi = max(hi,i);			
		}
		if(a[i]==mex-1){
			cnt++;
		}
	}
	if(lo==INT64_MAX||hi==INT64_MIN){
		if(cnt>1) cout<<"YES\n";
		else cout<<"NO\n";
		continue;	
	}
	for(int i = lo; i<=hi; i++){
		a[i] = mex;
	}
	// peek(a)
	set<int> ns;
	for(int i = 0; i<n; i++){
		ns.insert(a[i]);
	}
	int newmex = 0;
	for(int e : ns){
		if(e>newmex){
			break;
		} else if(e==newmex){
			newmex++;
		}
	}
	// cout<<mex<<" ";
	// cout<<lo<<" "<<hi<<" ";
	// cout<<newmex<<" ";
	if(newmex==mex+1){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}