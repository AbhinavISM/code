#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int solve(int q, int n, int m, vector<int> &changes, vector<int> &left, vector<int> &right){
	int lo = 1;
	int hi = q;
	int ans = INT_MAX;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		vector<bool> setbits(n+1,0);
		vector<int> setbitsprefix(n+1,0);
		for(int i = 1; i<=mid; i++){
			setbits[changes[i]] = 1;
		}
		for(int i = 1; i<=n; i++){
			setbitsprefix[i] = setbitsprefix[i-1] + setbits[i];
		}
		int goodcount = 0;
		for(int i = 1; i<=m; i++){
			int lengthOfRange = right[i]-left[i]+1;
			int numberOf1s = setbitsprefix[right[i]] - setbitsprefix[left[i]-1];
			if(numberOf1s>lengthOfRange-numberOf1s){
				goodcount++;
			}
		}
		if(goodcount==0){
			lo = mid+1;
		} else if(goodcount>=1){
			ans = min(ans, mid);
			hi = mid-1;
		}
	}
	if(ans==INT_MAX){
		return -1;
	} else {
		return ans;
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int> left(m+1);
	vector<int> right(m+1);
	for(int i = 1; i<=m; i++){
		int li;
		cin>>li;
		int ri;
		cin>>ri;
		left[i] = li;
		right[i] = ri;
	}
	int q;
	cin>>q;
	vector<int> changes(q+1);
	for(int i = 1; i<=q; i++){
		int x;
		cin>>x;
		changes[i] = x;
	}
	cout<<solve(q,n,m,changes,left,right)<<"\n";
}
	return 0;
}