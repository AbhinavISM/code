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
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<int> peeche(n,1);
	vector<int> aage(n,1);
	map<int,int> before;
	map<int,int> after;
	for(int i = 0; i<n; i++){
		if(before[array[i]]==0){
			before[array[i]] = 1;
		} else {
			peeche[i] = 0;
		}
	}
	for(int i=n-1; i>=0; i--){
		if(after[array[i]]==0){
			after[array[i]] = 1;
		} else {
			aage[i] = 0;
		}
	}
	for(int i = 1; i<n; i++){
		aage[i] += aage[i-1];
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(peeche[i]){
			if(i!=0) ans += aage[n-1] - aage[i-1];
			else ans += aage[n-1];
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}