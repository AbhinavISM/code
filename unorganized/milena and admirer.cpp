#include<bits/stdc++.h>
#define int long long
#define ld long double
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
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
	int ans = 0;
	for(int i = n-2; i>=0; i--){
		// cout<<array[i]<<" "<<array[i+1]<<"\n";
		if(array[i]>array[i+1]){
			// cout<<"hehe ";
			int mod = array[i]%array[i+1];
			// cout<<mod<<"\n";
			if(mod==0){
				ans += array[i]/array[i+1];
				ans--;
				array[i] = array[i+1];
			} else {
				ans += array[i]/array[i+1];
				array[i] = array[i]/((array[i]/array[i+1])+1);
			}
		}
	}
	// peek(array)
	cout<<ans<<"\n";
}
	return 0;
}