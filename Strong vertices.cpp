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
	vector<int> arraya(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		arraya[i] = item;
	}
	vector<int> arrayb(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		arrayb[i] = item;
	}
	map<int,vector<int>> indexes;
	for(int i = 0; i<n; i++){
		if(indexes.find(arraya[i]-arrayb[i])==indexes.end()){
			vector<int> thisvalindexes;
			thisvalindexes.push_back(i+1);
			indexes[arraya[i]-arrayb[i]] = thisvalindexes; 
		} else {
			indexes[arraya[i]-arrayb[i]].push_back(i+1);
		}
	}
	pair<int,vector<int>> item = *(--indexes.end());
		cout<<item.second.size()<<"\n";
		for(auto ans : item.second){
			cout<<ans<<" ";
		}
	
	
	cout<<"\n";

}
	return 0;
}