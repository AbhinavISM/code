#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
pair<int,int> customLowerBound(vector<pair<int,int>> &sorted, int diff){
	int lo = 0;
	int hi = sorted.size()-1;
	int val = INT_MAX;
	int idx = -1;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		if(sorted[mid].first>=diff){
			if(sorted[mid].first<val){
				val = sorted[mid].first;
				idx = sorted[mid].second;
			}
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}
	if(idx!=-1){
		return make_pair(val,idx);
	} else {
		return (*(sorted.rbegin()));
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int> array(n);
	vector<pair<int,int>> sorted(n);
	int maxi = INT_MIN;
	int maxidx = -1;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		if(item>maxi){
			maxi = item;
			maxidx = i;
		}
	}
	for(int i = 0; i<n; i++){
		sorted[i] = make_pair(array[i],i);
	}
	sort(sorted.begin(), sorted.end());
	vector<pair<int, int>> ans;
	int numops = 0;
	int last = array[0];
	for(int i = 1; i<n; i++){
		while(array[i]<last){
			int diff = last-array[i];
			// int j = -1;
			// int minfound = INT_MAX;
			// for(int i = 1; i<=n; i++){
			// 	if(array[i]>=diff&&array[i]<=minfound){
			// 		j = i;
			// 		minfound = array[i];
			// 	}
			// }
			pair<int,int> it = customLowerBound(sorted,diff);
			int j = (it).second;
			ans.push_back({i,j});
			numops++;
			array[i] += (it).first;
		}
		last = array[i];
	}
	cout<<numops<<"\n";
	for(auto a : ans){
		cout<<a.first+1<<" "<<a.second+1<<"\n";
	}
	cout<<"\n";
}
	return 0;
}