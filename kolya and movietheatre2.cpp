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
	int m;
	cin>>m;
	int d;
	cin>>d;
	multiset<int> selectedElements;
	int sum = 0;
	int maxsum = 0;
	int selectCount = 0;
	// set<int> unselected;
	int lastItem;
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		if(item<0){
			sum = sum-d;
			continue;
		}
		if(selectCount<m){
				sum = sum-d+item;
				selectCount++;
				selectedElements.insert(item);
		}else {
				// if(unselected.size()>0 && *(unselected.rbegin())>lastItem){
				// 	sum -= lastItem;
				// 	sum += *(unselected.rbegin());
				// 	selectedElements.insert(*(unselected.rbegin()));
				// 	selectedElements.erase(selectedElements.begin());
				// }
				sum = sum-d+item;
				selectedElements.insert(item);
				sum -= (*(selectedElements.begin()));
				selectedElements.erase(selectedElements.begin());
				// unselected.insert(*(selectedElements.begin()));
		}
		if(maxsum<=sum){
			maxsum = sum;
		}
		// lastItem = item;
	}
	if(maxsum>0){
		cout<<maxsum<<"\n";
	} else {
		cout<<0<<"\n";
	}
}
	return 0;
}