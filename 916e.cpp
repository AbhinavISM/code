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
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	vector<int> b(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		b[i] = item;
	}
	vector<pair<int, pair<int,int>>> m;
	for(int i = 0; i<n; i++){
		if(a[i]!=0&&b[i]!=0){
			m.push_back(make_pair(a[i]+b[i],make_pair(a[i],b[i])));
		}
	}
	sort(m.begin(), m.end(), greater<pair<int, pair<int,int>>>());
	int ans = 0;
	bool alice = true;
	for(auto p : m) {
		if(alice){
			ans += (p.second.first-1ll);
		} else {
			ans -= (p.second.second-1ll);
		}
		alice = !alice;
	}
	cout<<ans<<"\n";
}
	return 0;
}