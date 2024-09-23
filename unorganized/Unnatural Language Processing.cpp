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
	string s;
	cin>>s;
	vector<char> ans;
	for(int i = n-1; i>=0; i--){
		if(s[i]=='a'||s[i]=='e'){
			ans.push_back(s[i]);
			ans.push_back(s[i-1]);
			ans.push_back('.');
			i--;
		} else {
			ans.push_back(s[i]);
			ans.push_back(s[i-1]);
			ans.push_back(s[i-2]);
			ans.push_back('.');
			i-=2;
		}
	}
	for(int i = ans.size()-2; i>=0; i--){
		cout<<ans[i];
	}
	cout<<"\n";
}
	return 0;
}