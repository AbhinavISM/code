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
	int k;
	cin>>k;
	vector<int> array(n);
	vector<int> setCount(31,0);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		int bitnumber = 30;
		while(item!=0){
			if(item%2){
				setCount[bitnumber]++;
			}
			item/=2;
			bitnumber--;
		}
	}
	for(int i = 30; i>=0; i--){
		// cout<<setCount[i]<<" ";
	}
	for(int i = 0; i<31; i++){
		int useneeded = n-setCount[i];
		if(useneeded<=k){
			k-=useneeded;
			setCount[i] = n;	
			// cout<<k<<"\n";
		}
	}
	int ans = 0;
	int twokipower = 1073741824;
	for(int i = 0; i<31; i++){
		if(setCount[i]==n){
			// cout<<"allsetbit "<<i<<"\n";
			ans += twokipower;
		}
		twokipower /= 2;
	}
	cout<<ans<<"\n";
	// cout<<"next\n";
}
	return 0;
}