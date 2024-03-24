#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int squareRoot(int x){
	int hi = 2000000000;
	int lo = 0;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		if(mid*mid==x){
			return mid;
		} else if(mid*mid<x){
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	return -1;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	map<int,int> valindexes;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(valindexes.find(item)==valindexes.end()){
			valindexes.insert({item,0});
			valindexes[item]++;
		} else {
			valindexes[item]++;
		}
	}
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		int y;
		cin>>y;
		if(x*x<4*y){
			cout<<0<<" ";
			continue;
		}
		int rootpart = squareRoot(x*x-4*y);
		if(rootpart==-1){
			cout<<0<<" ";
			continue;
		}
		if((x+rootpart)%2==1||(x-rootpart)%2==1){
			cout<<0<<" ";
			continue;
		}
		int ai = (x+rootpart)/2;
		int aj = (x-rootpart)/2;
		if(valindexes.find(ai)==valindexes.end()||valindexes.find(aj)==valindexes.end()){
			cout<<0<<" ";
			continue;
		}
		int temp = 200000;
		if(ai==aj){
			cout<<((valindexes[ai]-1)*(valindexes[ai]))/2;
			// cout<<((temp)*(temp-1))/2;
		} else {
			cout<<valindexes[ai]*valindexes[aj];
		}
		cout<<" ";
	}
	cout<<"\n";
}
	return 0;
}