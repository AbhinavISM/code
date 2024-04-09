#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n,0);
	multiset<int> aset;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		aset.insert(a[i]);
	}
	vector<int> b(m,0);
	multiset<int> bset;
	for(int i = 0; i<m; i++){
		cin>>b[i];
		bset.insert(b[i]);
	}
	multiset<int> adone;
	multiset<int> bdone;
	int ans = 0;
	int match = 0;
	for(int j = 0; j+m-1<=n-1; j++){
		if(j==0){
			for(int i = j; i<j+m; i++){
				adone.insert(a[i]);
				aset.erase(aset.find(a[i]));
				if(bset.find(a[i])!=bset.end()){
					match++;
					bset.erase(bset.find(a[i]));
					bdone.insert(a[i]);
				}
			}
			if(match>=k) ans++;
		} else {
			adone.erase(adone.find(a[j-1]));
			if(adone.count(a[j-1])<bdone.count(a[j-1])){
				match--;
				bset.insert(a[j-1]);
				bdone.erase(bdone.find(a[j-1]));
			}
			adone.insert(a[j+m-1]);
			aset.erase(aset.find(a[j+m-1]));
			if(bset.find(a[j+m-1])!=bset.end()){
				match++;
				bset.erase(bset.find(a[j+m-1]));
				bdone.insert(a[j+m-1]);
			}
			if(match>=k) ans++;
		}
		// peek(bdone)
	}
	cout<<ans<<"\n";
}
	return 0;
}