#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x;cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	vector<char> ans;
	ans.push_back(a[0]);
	for(int i = 0; i<n-1; i++){
		if(a[i+1]=='0'){
			ans.push_back('0');
		} else if(a[i+1]==b[i]){
			ans.push_back(a[i+1]);
		} else {
			while(i<n-1){
				ans.push_back(b[i]);
				i++;
			}
		}
	}
	ans.push_back(b[n-1]);
	peek(ans)
	int badidx = -1;
	for(int i = n-1; i>=0; i--){
		if(ans[i+1]!=b[i]){
			badidx = i;
			break;
		}
	}
	// cout<<badidx<<"\n";
	int cnt = 0;
	for(int i = 0; i<n; i++){
		if(a[i]==ans[i]){
			if(b[i]==ans[i+1]&&i>badidx){
				cnt++;
			}
		} else {
			break;
		}
	}
	cout<<cnt<<"\n";
}
	return 0;
}