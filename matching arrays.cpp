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
	int x;
	cin>>x;
	vector<pair<int,int>> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = {item,i};
	}
	vector<pair<int, int>> b(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		b[i] = {item,i};
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> ans;
	for(int i = x; i<n; i++){
		ans.push_back(b[i].first);
	}
	for(int i = 0; i<x; i++){
		ans.push_back(b[i].first);
	}
	int bt = 0;
	for(int i = 0; i<n; i++){
		if(a[i].first>ans[i]){
			bt++;
		}
	}
	if(bt==x){
		cout<<"YES\n";
		vector<pair<int,int>> finalans;
		for(int i = 0; i<n; i++){
			finalans.push_back({a[i].second,ans[i]});
		}
		sort(finalans.begin(), finalans.end());
		for(int i = 0; i<n; i++){
			cout<<finalans[i].second<<" ";
		}
		cout<<"\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}