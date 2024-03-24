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
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	multiset<int, greater<int>> zero;
	int total = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		int zcnt = 0;
		while(item%10==0&&item>0){
			zcnt++;
			total++;
			item/=10;
		}
		while(item>0){
			total++;
			item/=10;
		}
		if(zcnt>0)zero.insert(zcnt);
	}
	int deleted = 0;
	bool anna = true;
	while(zero.size()>0){
		if(anna){
			deleted += (*zero.begin());
			zero.erase(zero.begin());
		} else {
			zero.erase(zero.begin());
		}
		anna = (!anna);
	}
	if(total-deleted-1>=m){
		cout<<"Sasha\n";
	} else {
		cout<<"Anna\n";
	}
}
	return 0;
}