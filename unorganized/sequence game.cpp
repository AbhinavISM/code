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
	vector<int> array;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array.push_back(item);
	}
	vector<int> ans;
	ans.push_back(array[0]);
	int last = array[0];
	for(int i = 1; i<n; i++){
		if(array[i]>=last){
			ans.push_back(array[i]);
			last = array[i];
		} else {
			ans.push_back(array[i]);
			ans.push_back(array[i]);
			last = array[i];
			
			// i = i-1;
		}
	}
	cout<<ans.size()<<"\n";
	for(int i = 0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
}
	return 0;
}