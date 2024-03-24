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
	vector<vector<int>> array(n,vector<int>());
	vector<set<int>> freq(50,set<int>());
	for(int i = 0; i<n; i++){
		int k;
		cin>>k;
		for(int j = 0; j<k; j++){
			int item;
			cin>>item;
			// cout<<item;
			array[i].push_back(item-1);
			freq[item-1].insert(i);
		}
	}
	// int a = 0;
	// for(auto i : freq){
	// 	cout<<"i :"<<a<<" ";
	// 	a++;
	// 	for(auto j : i){
	// 		cout<<j<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	int ans = 0;
	for(int i = 0; i<50; i++){
		set<int> num;
		if(freq[i].size()!=0){
			for(int j = 0; j<n; j++){
				if(freq[i].find(j)==freq[i].end()){
					for(int k = 0; k<array[j].size(); k++){
						num.insert(array[j][k]);
					}
				}
			}
		}
		int size = num.size();
		// cout<<size<<" ";
		ans = max(ans, size);
	}
	cout<<ans<<"\n";
}
	return 0;
}