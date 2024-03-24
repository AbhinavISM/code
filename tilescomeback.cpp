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
	unordered_set<int> found;
	vector<int> presum(n-1);
	for(int i = 0; i<n-1; i++){
		int item;
		cin>>item;
		presum[i] = item;
	}
	found.insert(presum[0]);
	for(int i = 1; i<n-1; i++){
		if(i==n-2){
			
		}
		found.insert(presum[i] - presum[i-1]);
	}

	int leftSum = 0;
	for(int i = 1; i<=n; i++){
		if(found.find(i)==found.end()){
				leftSum += i;
		}
	}
	if(found.count(leftSum)==1&&leftSum>n){
		cout<<"YES";
	} else if(found.count(leftSum)==2&&leftSum<=n){
		cout<<"YES";
	} else {
		cout<<"NO";
	}
	cout<<"\n";
}
	return 0;
}