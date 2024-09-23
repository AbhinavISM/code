#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	string x;
	string y;
	cin>>x;
	cin>>y;
	int decide = -1;
	for(int i = 0; i<x.size(); i++){
		if(x[i]!=y[i]) {
			decide = i;
			break;
		}
	}
	if(decide==-1||decide==x.size()-1){
		cout<<x<<"\n"<<y<<"\n";
		continue;
	}
	for(int i = decide+1; i<x.size(); i++){
		if(x[decide]>y[decide]&&x[i]>y[i]){
			char tmp = x[i];
			x[i] = y[i];
			y[i] = tmp;
		} else if(x[decide]<y[decide]&&x[i]<y[i]){
			char tmp = x[i];
			x[i] = y[i];
			y[i] = tmp;
		}
	}
		cout<<x<<"\n"<<y<<"\n";
	
}
	return 0;
}