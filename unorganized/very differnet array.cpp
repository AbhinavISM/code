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
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	vector<int> a1(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		a1[i] = item;
	}
	sort(a.begin(), a.end());
	sort(a1.begin(), a1.end(), greater<int>());
	multiset<int> b;
	for(int i = 0; i<m; i++){
		int item;
		cin>>item;
		b.insert(item);
	}
	int ans = 0;
	int i=0;
	int j=0;
	while(i+j<n){
		int md1 = 0;
		int d1 = abs(a[i]-(*(b.begin())));
		int d2 = abs(a[i]-(*(b.rbegin())));
		if(d2>=d1){
			md1 = d2;
		} else {
			md1 = d1;
		}
		int md2 = 0;
		int d3 = abs(a1[j]-(*(b.begin())));
		int d4 = abs(a1[j]-(*(b.rbegin())));
		if(d4>d3){
			md2 = d4;
		} else {
			md2 = d3;
		}
		if(md1>=md2){
			i++;
			ans += md1;
			if(d2>=d1){
				b.erase((--b.end()));
			} else {
				b.erase(b.begin());
			}
		} else {
			j++;
			ans += md2;
			if(d4>d3){
				b.erase((--b.end()));
			} else {
				b.erase(b.begin());
			}
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}