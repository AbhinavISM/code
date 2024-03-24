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
	map<int, int> primefrequency;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		for(int j = 2; j*j<=item; j++){
			int cnt = 0;
			while(item%j==0){
				item/=j;
				cnt++;
			}
			primefrequency[j] += cnt;
			// cout<<cnt<<" ";
		}
		if(item!=1){
			primefrequency[item] += 1;
		}
		// cout<<"\n";
	}
	bool ans = true;
	for(auto freqp : primefrequency){
		if(freqp.second%n!=0){
			ans = false;
		}
	}
	if(ans){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}