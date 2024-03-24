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
	int maxxor = INT_MIN;
	vector<int> array(n);
	vector<vector<bool>> allXorPossibilities(n,vector<bool>(256,0));
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		allXorPossibilities[i][item] = true;
	}
	for(int i=1; i<n; i++){
		for(int j = 0; j<256; j++){
			if(allXorPossibilities[i-1][j]){
				allXorPossibilities[i][j^array[i]] = true;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j = 0; j<256; j++){
			if(allXorPossibilities[i][j]){
				maxxor = max(maxxor, j);
			}
		}
	}
	cout<<maxxor<<"\n";
}
	return 0;
}