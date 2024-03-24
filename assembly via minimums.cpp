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
	map<int,int> freq;
	for(int i = 0; i<(n*(n-1))/2; i++){
		int item;
		cin>>item;
		if(freq.find(item)==freq.end()){
			freq[item] = 1;
		} else {
			freq[item]+=1;
		}
	}
	vector<int> ans;
	int left = n-1;
	int largest;
	for(auto item : freq){
		while(item.second){
			item.second -= left;
			left--;
			ans.push_back(item.first);
		}
		largest = item.first;
	}
	for(int item : ans){
		cout<<item<<" ";
	}
	cout<<largest;
	cout<<"\n";
}
return 0;
}