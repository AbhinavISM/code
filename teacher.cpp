#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	int n;
	cin>>n;
	vector<pair<string, string>> a;
	for(int i = 0; i<n; i++){
		string s1;
		cin>>s1;
		string s2;
		cin>>s2;
		a.push_back({s1,s2});
	}
	sort(a.begin(), a.end());
	for(int i = 0; i<n; i++){
		cout<<a[i].first<<" "<<a[i].second<<"\n";
	}
}