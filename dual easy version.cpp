#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second < b.second);
}
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
void updateSortedArray(vector<pair<int,int>> &sorted, pair<int,int> toBeSearched, int valueToIncrease){
	int hi = sorted.size()-1;
	int lo = 0;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		if(sorted[mid].first==toBeSearched.first){
			if(sorted[mid].second==toBeSearched.second){
				sorted[mid].first += valueToIncrease;
				return;
			} else if(sorted[mid].second>toBeSearched.second){
				hi = mid-1;
			} else {
				lo = mid+1;
			}
		} else if(sorted[mid].first>toBeSearched.first){
			hi = mid-1;
		} else {
			lo = mid+1;
		}
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
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	for(int i = 0; i<n; i++){
		sorted[i] = make_pair(array[i],i);
	}
	sort(sorted.begin(), sorted.end(),sortbyCond);
	vector<pair<int, int>> ans;
	int numops = 0;
	int last = array[0];
	for(int i = 1; i<n; i++){
		while(array[i]<last){
			int diff = last-array[i];
			pair<int,int> it = customLowerBound(sorted,diff);
			int j = (it).second;
			ans.push_back({i,j});
			numops++;
			updateSortedArray(sorted,make_pair(array[i],i),(it).first);
			sort(sorted.begin(), sorted.end(),sortbyCond);
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