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
	int n,x;
	cin>>n>>x;
	int ans = 0;
	int a = (n-x);
	set<int> kval;
	for(int d = 1; d*d<=a; d++){
		if(a%d==0){
			if(d%2==0&&((d+2)/2)>=x){
				kval.insert((d+2)/2);
			}
			if((a/d)%2==0&&(((a/d)+2)/2)>=x){
				kval.insert(((a/d)+2)/2);
			}
		}
	}
	if(x!=1){
		int b = (n+x-2);
		for(int d = 1; d*d<=b; d++){
			if(b%d==0){
				if(d%2==0&&((d+2)/2)>=x){
					kval.insert((d+2)/2);
				}
				if((b/d)%2==0&&(((b/d)+2)/2)>=x){	
					kval.insert(((b/d)+2)/2);
				}
			}
		}
	}
	cout<<kval.size()<<"\n";
}
	return 0;
}