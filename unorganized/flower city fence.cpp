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
	vector<int> ansarr;
	int diff;
	int flag = false;
	for(int i = n-1; i>=0; i--){
		if(i==n-1){
			diff = array[i];
		} else {
			diff = array[i] - array[i+1];
		}
		for(int j = 0; j<diff; j++){
			ansarr.push_back(i+1);
			if(ansarr.size()>n){
				flag = true;
				break;
			}
		}
	}
	if(flag){
		cout<<"NO\n";
		continue;
	}
	if(ansarr==array){
		cout<<"YES";
	} else {
		cout<<"NO";
	}
	// for(int ans : ansarr){
	// 	cout<<ans<<" ";
	// }
	cout<<"\n";
}
	return 0;
}