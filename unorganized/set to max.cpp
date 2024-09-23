#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<int> a(n+2,0);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	vector<int> b(n+2,0);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		b[i] = item;
	}
	vector<pair<int,int>> sortedb(n+1);
	sortedb[0] = {0,0};
	for(int i = 1; i<=n; i++){
		sortedb[i] = {b[i], i};
	}
	sort(sortedb.begin(), sortedb.end());
	for(int i = 1; i<=n; i++){
		if(a[sortedb[i].second]>sortedb[i].first){
			cout<<"NO\n";
			return;
		}
		else if(a[sortedb[i].second]<sortedb[i].first){
			int j = sortedb[i].second;
			int r = -1;
			int maxi = INT_MIN;
			for(int k = j+1; k<=n&&b[k]>=b[j]; k++){
				maxi = max(maxi, a[k]);
				if(maxi==b[j]){
					r = k;
					break;
				}
			}
			for(int k = j; k<=r; k++){
				a[k] = b[j];
			}
			if(a[j]!=b[j]){
				int r = INT_MAX;
				int maxi = INT_MIN;
				for(int k = j-1; k>=1&&b[k]>=b[j]; k--){
					maxi = max(maxi, a[k]);
					if(maxi==b[j]){
						r = k;
						break;
					}
				}
				for(int k = j; k>=r; k--){
					a[k] = b[j];
				}
			}
			if(a[j]!=b[j]){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
	return;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	solve();
	// vector<map<int, set<int>>> freq(n);
	// map<int, set<int>> currfound;
	// for(int i = n-1; i>=0; i--){
	// 	if(currfound.find(a[i])==currfound.end()){
	// 		currfound[a[i]] = set<int>();
	// 		currfound[a[i]].insert(i);
	// 		freq[i] = currfound;
	// 	} else {
	// 		currfound[a[i]].insert(i);
	// 		freq[i] = currfound;
	// 	}
	// }

		// if(freq[i].find(b[i])!=freq[i].end()){
			// 	int l = i;
			// 	int r = *(freq[i][b[i]].begin());
			// 	for(int j = l; j<=r; j++){
			// 		a[j] = b[i];
			// 	}
			// } else {
			// 	break;
			// }
	
}
	return 0;
}