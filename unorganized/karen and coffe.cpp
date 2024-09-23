#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int k;
	cin>>k;
	int q;
	cin>>q;
	vector<pair<int,int>> recipies(n);
	for(int i = 0; i<n; i++){
		pair<int,int> recipie;
		cin>>recipie.first;
		cin>>recipie.second;
		recipies[i] = recipie;
		// cout<<recipie.first<<" "<<recipie.second<<"\n";
	}
	vector<pair<int,int>> queries(q);
	for(int i = 0; i<q; i++){
		pair<int,int> query;
		cin>>query.first;
		cin>>query.second;
		queries[i] = query;
		// cout<<query.first<<" "<<query.second<<"\n";
	}
	vector<int> prefix(200002,0);
	for(int i = 0; i<n; i++){
		prefix[recipies[i].first] += 1;
		prefix[recipies[i].second+1] += -1;
	}
	for(int i = 1; i<=200001; i++){
		prefix[i] += prefix[i-1];
		// cout<<prefix[i]<<" ";
	}
	vector<int>admissiblePrefix(200001,0);
	for(int i = 1; i<200001; i++){
		if(prefix[i]>=k){
			admissiblePrefix[i]++;
		}
	}
	for(int i = 1; i<200001; i++){
		admissiblePrefix[i] += admissiblePrefix[i-1];
	}
	for(int i = 0; i<q; i++){
		cout<<admissiblePrefix[queries[i].second] - admissiblePrefix[queries[i].first-1]<<"\n";
	}
	return 0;
}