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
	vector<int> a(n+1);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	vector<int> p(n+1);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		p[i] = item;
	}
	multiset<int,greater<int>> canpick;
	for(int i = 1; i<=n; i++){
		canpick.insert(a[i]);
	}
	multiset<int> picked;
	picked.insert(*canpick.begin());
	canpick.erase(canpick.begin());
	int ans = *picked.begin();
	int mush = 1;
	for(int i = 2; i<=n; i++){
		if(canpick.find(a[p[i-1]])!=canpick.end()){
			canpick.erase(canpick.find(a[p[i-1]]));
			if(canpick.size()>0) picked.insert(*canpick.begin());
			else break;
			canpick.erase(canpick.begin());
			if(ans<((*picked.begin())*picked.size())){
				ans = ((*picked.begin())*picked.size());
				mush = picked.size();
			}
		} else {
			picked.erase(picked.find(a[p[i-1]]));
			if(canpick.size()>=2){
				picked.insert(*canpick.begin());
				canpick.erase(canpick.begin());
				picked.insert(*canpick.begin());
				canpick.erase(canpick.begin());
			} else {
				break;
			}
			if(ans<((*picked.begin())*picked.size())){
				ans = ((*picked.begin())*picked.size());
				mush = picked.size();
			}
		}
	}
	cout<<ans<<" "<<mush<<"\n";
}
	return 0;
}