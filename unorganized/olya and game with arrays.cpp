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
	vector<int> secmins;
	vector<int> mins;
	int n;
	cin>>n;
	vector<vector<int>> array;
	int mini = INT_MAX;
	int secmini = INT_MAX;
	for(int i = 0; i<n; i++){
		int mi;
		cin>>mi;
		int mini = INT_MAX;
		int secmini = INT_MAX;
		array.push_back(vector<int>());
		for(int j = 0 ; j<mi; j++){
			int item;
			cin>>item;
			if(item<=mini){
				secmini = mini;
				mini = item;
			} else if(item>mini&&item<=secmini){
				secmini = item;
			}
			array[i].push_back(item);
		}
		mins.push_back(mini);
		secmins.push_back(secmini);
		// cout<<secmins[i]<<" ";
		// cout<<secmini<<" ";
	}
	sort(secmins.begin(), secmins.end());
	sort(mins.begin(), mins.end());
	// for(int i = 0; i<n; i++){
	// 	cout<< secmins[i] <<" ";
	// }
	int ans = 0;
	for(int i = 1; i<n; i++){
		ans += secmins[i];
	}
	ans += mins[0];
	cout<<ans<<"\n";
}
	return 0;
}