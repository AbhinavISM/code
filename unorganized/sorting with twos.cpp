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
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	bool bad = false;
	int i = 0;
	for(i=3; i<n&&i<4; i++){
		if(array[i]<array[i-1]){
			bad = true;
		}
	}
	for(i=5; i<n&&i<8; i++){
		if(array[i]<array[i-1]){
			bad = true;
		}
	}
	for(i=9; i<n&&i<16; i++){
		if(array[i]<array[i-1]){
			bad = true;
		}
	}
	for(i=17; i<n; i++){
		if(array[i]<array[i-1]){
			bad = true;
		}
	}
	if(bad){
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
	}
}
	return 0;
}