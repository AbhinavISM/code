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
	vector<pair<int,int>> array(n+1);
	vector<int> ans(n+1,n);
	int total = 0;
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i].first = item;
		array[i].second = i;
	}
	sort(array.begin(), array.end());
	for(int i = 1; i<=n; i++){
		total+=array[i].first;
		ans[i]+=array[i].first*(2*i-1);
		ans[i]-=(n*array[i].first);
	}
	int subthird = 0;
	for(int i = 2; i<=n; i++){
		subthird+=array[i-1].first;
		ans[i]-=subthird;
	}
	int subsecond = 0;
	for(int i = n; i>=2; i--){
		subsecond+=array[i].first;
		ans[i-1] += subsecond;
	}
	int skip = 1;
	vector<int> finalans(n+1);
	for(int i = 1; i<=n; i++){
		pair<int,int> p = array[i];
		finalans[p.second] = ans[i];
	}
	for(int i = 1; i<=n; i++){
		cout<<finalans[i]<<" ";
	}
	cout<<"\n";
}
	return 0;
}