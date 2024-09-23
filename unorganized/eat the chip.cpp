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
	int h,w,xa,ya,xb,yb;
	cin>>h>>w>>xa>>ya>>xb>>yb;
	if(abs(xa-xb)%2){
		bool alice = true;
		while(ya!=yb&&xa<xb){
			if(ya>yb){
				if(alice){
					if(ya>1)ya--;
					xa++;
				} else {
					if(yb>1)yb--;
					xb--;
				}
			} else {
				if(alice){
					if(ya<w)ya++;
					xa++;
				} else {
					if(yb<w)yb++;
					xb--;
				}
			}
			alice = !alice;
		}
		if(ya==yb&&xa<=xb){
			cout<<"Alice\n";
		} else {
			cout<<"Draw\n";
		}
	} else {
		bool alice = true;
		while(ya!=yb&&xa<xb){
			if(ya>yb){
				if(alice){
					if(ya<w)ya++;
					xa++;
				} else {
					if(yb<w)yb++;
					xb--;
				}
			} else {
				if(alice){
					if(ya>1)ya--;
					xa++;
				} else {
					if(yb>1)yb--;
					xb--;
				}
			}
			alice = !alice;
		}
		if(ya==yb&&xa<=xb){
			cout<<"Bob\n";
		} else {
			cout<<"Draw\n";
		}
	}
}
	return 0;
}