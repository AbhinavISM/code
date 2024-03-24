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
	int d = 0;
	int ans = 0;
	for(int i = 0; i<n; i++){
		// cout<<array[i]-d;
		if(array[i]-d>=0){
			ans += array[i]-d;
			d += array[i]-d;
		} else {
			d = array[i];
		}
		// cout<<d<<" ";
	}
	cout<<ans-1<<"\n";
}
	return 0;
}