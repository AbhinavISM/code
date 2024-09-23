#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	set<int> a;
	for(int i = 1; i<=2*n; i++){
		a.insert(i);
	}
	vector<int> ans(2*n);
	int i = 0;
	bool inc = true;
	while(!a.empty()){
		if(inc){
			ans[i] = *a.begin();
			a.erase(a.begin());
			ans[i + n] = *a.begin();
			a.erase(a.begin());
		} else {
			ans[i + n] = *a.begin();
			a.erase(a.begin());
			ans[i] = *a.begin();
			a.erase(a.begin());
		}
		i++;
		inc = !inc;
	}
	// peek(ans)
	vector<int> ans2;
	for(int i = n+1; i<2*n; i++){
		ans2.push_back(ans[i]);
	}
	for(int i = 0; i<2*n; i++){
		ans2.push_back(ans[i]);
	}
	// peek(ans2)
	vector<int> pref(ans2.size() + 1,0);
	for(int i = 1; i<=ans2.size(); i++){
		pref[i] = pref[i-1] + ans2[i-1];
	}
	// peek(pref)
	int minsum = pref[n];
	int maxsum = pref[n];
	for(int i = 0; i<2*n; i++){
		minsum = min(minsum, pref[n+i] - pref[i]);
		maxsum = max(maxsum, pref[n+i] - pref[i]);
		// cout<<maxsum<<" "<<minsum<<"\n";
	}
	if(maxsum - minsum > 1){
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
		peek(ans)
	}
	return 0;
}