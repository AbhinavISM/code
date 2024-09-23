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
	int n;
	cin>>n;
	set<int> a;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a.insert(item);
	}
	int f = *a.begin();
	if(f!=1) {
		cout<<"Alice\n";
		continue;
	}
	bool alice = false;
	for(int i : a){
		alice = !alice;
		if(i==f){
			f++;
		} else {
			break;
		}
	}
	if(alice) cout<<"Alice\n";
	else cout<<"Bob\n";
}
	return 0;
}