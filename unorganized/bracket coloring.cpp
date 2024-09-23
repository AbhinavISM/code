#include<bits/stdc++.h>
#define int long long
#define ld long double
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
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
	string rev = "";
	stack<pair<char,int>> s1;
	stack<pair<char,int>> s2;
	vector<int> ans(n,1);
	int open = 0;
	int closed = 0;
	for(int i = 0; i<n; i++){
		rev += s[n-i-1];
		if(s[i]=='('){
			open++;
			s1.push({'(', i});
		} else if(s[i]==')'){
			closed++;
			if((!s1.empty())&&s1.top().first=='('){
				s1.pop();
			} else {
				s2.push({')', i});
			}
		}
	}
	if(open!=closed){
		cout<<-1<<"\n";
		continue;
	}
	while(!s1.empty()){
		ans[s1.top().second] = 2;
		s1.pop();
	}
	while(!s2.empty()){
		ans[s2.top().second] = 2;
		s2.pop();
	}
	int more = 1;
	for(int i = 1; i<n; i++){
		if(ans[i]!=ans[i-1]) more = 2;
	}
	if(more==1){
		cout<<more<<"\n";
		ans = vector<int>(n,1);
		peek(ans)
	} else {
		s = rev;
		stack<pair<char,int>> s1;
		stack<pair<char,int>> s2;
		vector<int> ans(n,1);
		for(int i = 0; i<n; i++){
			if(s[i]=='('){
				s1.push({'(', i});
			} else if(s[i]==')'){
				if((!s1.empty())&&s1.top().first=='('){
					s1.pop();
				} else {
					s2.push({')', i});
				}
			}
		}
		while(!s1.empty()){
			ans[s1.top().second] = 2;
			s1.pop();
		}
		while(!s2.empty()){
			ans[s2.top().second] = 2;
			s2.pop();
		}
		int more = 1;
		for(int i = 1; i<n; i++){
			if(ans[i]!=ans[i-1]) more = 2;
		}
		cout<<more<<"\n";
		if(more==1){
			ans = vector<int>(n,1);
		}
		for(int i = 0; i<n; i++){
			cout<<ans[n-i-1]<<" ";
		}
		cout<<"\n";
	}
}
	return 0;
}