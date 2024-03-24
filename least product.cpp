#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int> array(n);
	int pcnt = 0;
	int pidx;
	int ncnt = 0;
	int nidx;
	int zcnt = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		if(item>0){
			pcnt++;
			pidx = i;
		} else if(item==0){
			zcnt++;
		} else {
			ncnt++;
			nidx = i;
		}
	}
	if(zcnt>0){
		cout<<0<<"\n";
	} else if(ncnt==0){
		cout<<1<<"\n";
		cout<<pidx+1<<" "<<0<<"\n";
	} else if(ncnt>0){
		if(ncnt%2==0){
			cout<<1<<"\n";
			cout<<nidx+1<<" "<<0<<"\n";
		} else {
			cout<<0<<"\n";
		}
	}
}
	return 0;
}