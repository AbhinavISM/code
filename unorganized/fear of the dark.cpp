#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int px,py,ax,ay,bx,by;
	cin>>px>>py>>ax>>ay>>bx>>by;
	ld ans;
	ld hff = sqrt(((px-ax)*(px-ax))+((py-ay)*(py-ay)));
	ld hfs = sqrt(((px-bx)*(px-bx))+((py-by)*(py-by)));
	ld mff = sqrt(((ax)*(ax))+((ay)*(ay)));
	ld mfs = sqrt(((bx)*(bx))+((by)*(by)));
	if(mff<=mfs&&hff<=hfs){
		if(mff>hff){
			ans = mff;
		} else {
			ans = hff;
		}
	} else if(mff>=mfs&&hff>=hfs){
		if(mfs>hfs){
			ans = mfs;
		} else {
			ans = hfs;
		}
	} else if(mff<mfs&&hff>hfs){
		ld laltendistance = sqrt(((bx-ax)*(bx-ax))+((by-ay)*(by-ay)));
		ans = max(mff,hfs);
		ans = max((laltendistance/2), ans);
	} else {
		ld laltendistance = sqrt(((bx-ax)*(bx-ax))+((by-ay)*(by-ay)));
		ans = max(mfs,hff);
		ans = max((laltendistance/2), ans);
	}
	cout<<setprecision(12)<<ans<<"\n";
}
	return 0;
}