#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x+1<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
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
		a[i] = item-1;
	}
	vector<int> ta = a;
	sort(a.begin(), a.end());
	set<int> a1;
	set<int> a2;
	for(int i = 0; i<n; i++){
		a1.insert(i);
		a2.insert(i);
	}
	map<int,set<pair<int,int>>> m;
	bool flag = true;
	for(int i = 0; i<n; i++){
		if(a1.size()==0||a2.size()==0){
			flag = false;
			break;
		}
		if(a1.find(a[i])!=a1.end()){
			int smol = *(a2.begin());
			if(smol<=a[i]){
				if(m.find(a[i])==m.end()){
					m[a[i]] = set<pair<int,int>>();
				}
				m[a[i]].insert({a[i], smol});
				a1.erase(a[i]);
				a2.erase(a2.begin());
				continue;
			}
		}
		if(a2.find(a[i])!=a2.end()){
			int smol = *(a1.begin());
			if(smol<=a[i]){
				if(m.find(a[i])==m.end()){
					m[a[i]] = set<pair<int,int>>();
				}
				m[a[i]].insert({smol, a[i]});
				a2.erase(a[i]);
				a1.erase(a1.begin());
				continue;
			}
		}
		flag = false;
		break;
	}
	if(flag){
		cout<<"YES\n";
		vector<int> ans1;
		vector<int> ans2;
		for(int i = 0; i<n; i++){
			ans1.push_back((*(m[ta[i]].begin())).first);
			ans2.push_back((*(m[ta[i]].begin())).second);
			m[ta[i]].erase(m[ta[i]].begin());
		}
		peek(ans1)
		peek(ans2)
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}