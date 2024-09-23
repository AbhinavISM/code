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
	string s;
	cin>>s;
	vector<int> freq(26,0);
	for(int i = 0; i<n; i++){
		freq[s[i]-97]++;
	}
	int oddcnt = 0;
	for(int i = 0; i<26; i++){
		// cout<<freq[i]<<" ";
		if(freq[i]%2){
			oddcnt++;
		}
	}
	// cout<<oddcnt<<" "<<k<<" ";
	if(oddcnt>k+1){
		cout<<"NO\n";
	} else if((n-k)%2){
		cout<<"YES\n";
	} else {
			cout<<"YES\n";
		// if(oddcnt==k){
		// 	cout<<"YES\n";
		// } else {
		// 	cout<<"NO\n";
		// }
	}
}
	return 0;
}