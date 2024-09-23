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
	int amin = INT_MAX;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		amin = min(amin,item);
	}
	vector<int> barray(n);
	int bmin = INT_MAX;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		barray[i] = item;
		bmin = min(bmin, item);
	}
	int ans1 = 0;
	for(int i = 0; i<n; i++){
		ans1 += array[i] + bmin;
	}
	int ans2 = 0;
	for(int i = 0; i<n; i++){
		ans2 += barray[i] + amin;
	}
	// cout<<ans1<<" "<<ans2<<" ";
	cout<<min(ans1,ans2)<<"\n";

}
	return 0;
}