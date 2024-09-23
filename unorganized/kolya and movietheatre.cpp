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
	set<int> selectedElements;
	int sum = 0;
	int selectCount = 0;
	int minusFactor = 0;
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		if(selectCount<m){
			if(sum+minusFactor-i*d+item>sum){
				sum = sum+minusFactor-i*d+item;
				selectCount++;
				selectedElements.insert(item);
			}
		}else {
			if(sum+minusFactor-i*d+item-(*(selectedElements.begin())>sum)){
				sum = sum+minusFactor-i*d+item-(*(selectedElements.begin()));
				selectedElements.erase(selectedElements.begin());
				selectedElements.insert(item);
			}
		}
						minusFactor = i*d;

	}
	if(sum>0){
		cout<<sum<<"\n";
	} else {
		cout<<0<<"\n";
	}
}
	return 0;
}