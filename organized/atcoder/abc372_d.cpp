#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	vector<int> f(n,0);
	stack<int> s;
	for(int i = 0; i<n; i++){
		if(s.empty()||a[i]>=a[s.top()]){
			while(!s.empty()&&a[i]>=a[s.top()]) s.pop();
			f[i] += -1;
			if(s.empty())f[0] += 1;
			else f[s.top()] += 1;
			s.push(i);
		} else {
			f[i] += -1;
			f[s.top()] += 1;
			s.push(i);
		}
	}
	for(int i = 1; i<n; i++){
		f[i] += f[i-1];
	}
	peek(f)
	return 0;
}