#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int k;
	cin>>k;
	// cout<<n<<" ";
	int product = 1;
	bool good = true;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(2023%item!=0){
			good = false;
			// break;
		}
		product*=item;
		if(product>2023){
			good = false;
			// break;
		}
	}
	// cout<<product<<"\n";
	if(2023%product!=0){
		good = false;
	}
	if(good){
		cout<<"YES\n";
		cout<<2023/product<<" ";
		for(int i =0; i<k-1; i++){
			cout<<1<<" ";
		}
		cout<<"\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}