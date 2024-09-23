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
	multiset<int> ms;
	set<int> s;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		ms.insert(item);
		s.insert(item);
	}
	int ans = 0;
	for(int i : s){
		if(i!=2){
		int t = ms.count(i);
		ans += (t*(t-1))/2;
		} else {
			int t = ms.count(2) + ms.count(1);
			int t2 = ms.count(1);
			ans += (t*(t-1))/2;
			ans -= (t2*(t2-1))/2;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}