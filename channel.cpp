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
	int a;
	cin>>a;
	int q;
	cin>>q;
	string s;
	cin>>s;
	bool maybe = false;
	bool mustbe = false;
	int plusCount = a;
	int totalPlus = 0;
	if(a==n){
		cout<<"YES\n";
		continue;
	}
	for(int i = 0; i<q; i++){
		if(s[i]=='+'){
			plusCount++;
			totalPlus++;
		} else {
			plusCount--;
		}
		if(plusCount==n){
			mustbe = true;
		}
		if(totalPlus==n-a){
			maybe = true;
		}
	}
	if(mustbe){
		cout<<"YES\n";
	}
	else if(maybe){
		cout<<"MAYBE\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}