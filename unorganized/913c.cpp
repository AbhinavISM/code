#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> freq(26,0);
	for(int i = 0; i<n; i++){
		freq[s[i] - 97]++;
	}
	if(n%2==0){
		for(int i = 0; i<26; i++){
			if(freq[i]>=n/2) {
				cout<<2*freq[i] - n<<"\n";
				return;
			}
		}
	} else {
		for(int i = 0; i<26; i++){
			if(freq[i]>n/2) {
				cout<<2*freq[i] - n<<"\n";
				return;
			}
		}
	}
	if(n%2==0){
		cout<<0<<"\n";
	} else {
		cout<<1<<"\n";
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
}
	return 0;
}