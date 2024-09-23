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
	int maxi = INT_MIN;
	int secmaxi = INT_MIN;
	int mini = INT_MAX;
	int secmini = INT_MAX;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(item>=maxi){
			secmaxi = maxi;
			maxi = item;
		} else if(item>=secmaxi){
			secmaxi = item;
		}
		if(item<=mini){
			secmini = mini;
			mini = item;
		} else if(item<=secmini){
			secmini = item;
		}
	}
	cout<<abs(maxi - mini) + abs(mini - secmaxi) + abs(secmaxi - secmini) + abs(secmini - maxi)<<"\n";
}
	return 0;
}