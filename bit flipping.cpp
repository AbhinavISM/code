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
	vector<int> ans(n,0);
	if(k%2==0){
		for(int i = 0; i<n; i++){
			if(s[i]=='0'){
				ans[i] = 1;
				k--;
				if(k==0){
					break;
				}
			}
		}
	} else {
		for(int i = 0; i<n; i++){
			if(s[i]=='1'){
				ans[i] = 1;
				k--;
				if(k==0){
					break;
				}
			}
		}
	}
	for(int i = 0; i<n; i++){
		if((k-ans[i])%2){
			if(s[i]=='0'){
				s[i]=='1';
			} else {
				s[i]=='0';
			}
		}
	}
	cout<<s<<"\n";
	if(k>0) ans[n-1]+=k;
	for(int a : ans){
		cout<<a<<" ";
	}
	cout<<"\n";
}
	return 0;
}