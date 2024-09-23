#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	vector<int> prefact(200001,1);
	int fact = 1;
	for(int i = 2;i<200001; i++){
		fact = fact*i;
		fact%=998244353;
		prefact[i] = fact;
	}
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	char previous = s[0];
	int i = 1;
	int minops = 0;
	int ways = 1;
	int tofact = 0;
	while(i<s.length()){
		int contlen = 1;
		while(previous==s[i]&&i<s.length()){
			minops++;
			contlen++;
			i++;
		}
		if(contlen>1){
			ways *= contlen;
			ways%=998244353;
			tofact+=contlen-1;
		}
		if(i<s.length()){
			previous = s[i];
		}
		i++;
	}
	cout<<minops<<" "<<(ways*prefact[tofact])%998244353<<"\n";
}
	return 0;
}