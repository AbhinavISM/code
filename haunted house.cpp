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
	string s;
	cin>>s;
	int onecnt = 0;
	int zerocnt = 0;
	stack<int> zeropos;
	for(int i = 0; i<n; i++){
		if(s[i]=='0'){
			zeropos.push(i);
			zerocnt++;
		} else {
			onecnt++;
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		if(onecnt>n-i){
			cout<<-1<<" ";
		} else if(s[n-i]=='0'){
			zeropos.pop();
			cout<<ans<<" ";
		} else {
			int nxtzero = zeropos.top();
			s[nxtzero] = '1';
			s[n-i] = '0';
			zeropos.pop();
			ans += n-i-nxtzero;
			cout<<ans<<" ";
		}
	}
	cout<<"\n";
}
	return 0;
}