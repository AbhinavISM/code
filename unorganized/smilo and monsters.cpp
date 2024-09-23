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
	int cnt = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		ms.insert(item);
	}
	int ans = 0;
	int x = 0;
	while(ms.size()>1){
		int big = *(--ms.end());
		while(x<big&&ms.size()>1){
			int smol = *(ms.begin());
			if(x + smol <= big){
				x += smol;
				ms.erase(ms.begin());
			} else {
				ms.erase(ms.begin());
				ms.insert(smol - (big - x));
				x = big;
			}
		}
		if(x == big){
			ms.erase((--ms.end()));
			ans += (x+1);
			x = 0;
		} else {
			ans += (x+1);
			ans += (*(ms.begin()) - x)/2;
			ans += (*(ms.begin()) - x)%2;
			ms.erase((--ms.end()));
		}
	}
	if(ms.size()==1){
		ans += (*(ms.begin()))/2;
		ans += (*(ms.begin()))%2;
		if(*(ms.begin())>1) ans++;
	}
	cout<<ans<<"\n";
}
	return 0;
}