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
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	int l,b;
	if(x1==x2){
		l  = abs(y2-y1);
	} else if(x1==x3){
		l = abs(y3-y1);
	} else {
		l = abs(y4-y1);
	}
	if(y1==y2){
		b  = abs(x2-x1);
	} else if(y1==y3){
		b = abs(x3-x1);
	} else {
		b = abs(x4-x1);
	}
	cout<<l*b<<"\n";
}
	return 0;
}