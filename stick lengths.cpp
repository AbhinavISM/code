#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int findCost(vector<int> & array, int stickLength){
	int cost = 0;
	for(int i = 0; i<array.size(); i++){
		cost += abs(array[i]-stickLength);
	}
	return cost;
}
int findans(vector<int> & array, int &n, int maxheight){
	int r = maxheight;
	int l = 0;
	while(r-l>=3){
		int mid1 = (r+2*l)/3;
		int mid2 = (2*r+l)/3;
		int cost1 = findCost(array,mid1);
		int cost2 = findCost(array,mid2);
		if(cost2<cost1){
			l = mid1;
		} else {
			r = mid2;
		}
	}
	int mincost = INT64_MAX;
	for(int i = l; i<=r; i++){
		mincost = min(mincost, findCost(array, i));
	}
	return mincost;
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n);
	int maxheight = INT_MIN;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		maxheight = max(maxheight,item);
	}
	sort(array.begin(), array.end());
	cout<<findans(array,n,maxheight);
	return 0;
}