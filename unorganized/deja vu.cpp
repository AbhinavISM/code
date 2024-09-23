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
	int q;
	cin>>q;
	vector<int> array(n);
	vector<vector<int>> m(31);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		int j = 0;
		while(item>0){
			if(item%2){
				break;
			}
			item/=2;
			j++;
		}
		if(m[j].size()==0){
			m[j] = vector<int>();
		}
		m[j].push_back(i);
	}
	// vector<int> queries(n);
	for(int i = 0; i<q; i++){
		int query;
		cin>>query;
		for(int j = 30; j>=query; j--){
			for(int k : m[j]){
				array[k] += (1<<(query-1));
			}
			m[query-1].insert(m[query-1].end(), m[j].begin(), m[j].end());
			m[j] = vector<int>();
		}
	}
	for(int a : array){
		cout<<a<<" ";
	}
	cout<<"\n";
}
	return 0;
}