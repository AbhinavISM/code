#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
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
	if(n%2){
		cout<<-1<<"\n";
		continue;
	}
	vector<int> f(26,0);
	for(int i = 0; i<n; i++){
		f[s[i]-97]++;
	}
	bool toomuch = false;
	for(int i = 0; i<26; i++){
		if(f[i]>n/2){
			toomuch = true;
		}
	}
	if(toomuch){
		cout<<-1<<"\n";
		continue;
	}
	f = vector<int>(26,0);
	for(int i = 0; i<(n/2); i++){
		if(s[i]==s[n-i-1]) f[s[i]-97]++;
	}
	multiset<int, greater<int>> work;
	for(int i = 0; i<26; i++){
		if(f[i]>0) work.insert(f[i]);
	}
	int ans = 0;
	if(work.size()==0){
		cout<<0<<"\n";
		continue;
	}
	while(work.size()>1){
		int b = *(work.begin());
		int e = *(++(work.begin()));
		work.erase(work.begin());
		work.erase(work.begin());
		b--;
		e--;
		if(b>0)work.insert(b);
		if(e>0)work.insert(e);
		ans++;
	}
	if(work.size()==1) ans += (*(work.begin()));
	cout<<ans<<"\n";
}
	return 0;
}