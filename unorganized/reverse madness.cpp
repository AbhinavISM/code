#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int findIndex(vector<int> &r, int k, int x){
	int lo = 0;
	int hi = k;
	int ans = INT_MAX;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		if(x<=r[mid]){
			ans = min(mid, ans);
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}
	return ans;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int k;
	cin>>k;
	string s;
	cin>>s;

	vector<int> l(k);
	vector<int> r(k);
	for(int i = 0; i<k; i++){
		int item;
		cin>>item;
		l[i] = item;
	}
	for(int i = 0; i<k; i++){
		int item;
		cin>>item;
		r[i] = item;
	}
	int q;
	cin>>q;
	vector<int> queries(n+1,0);
	vector<int> reverseCount(n+1,0);
	while(q--){
		int x;
		cin>>x;
		queries[x]++;
	}
	int maxb = INT_MIN;
	int mina = INT_MAX;
	for(int x = 1; x<=n; x++){
		if(queries[x]%2==1){
			int a;
			int b;
			int index = findIndex(r,k,x);
			if(index==0){
				a = min(x, r[0]+1-x);
				b = max(x, r[0]+1-x);
			} else {
				a = min(x, r[index-1]+r[index]+1-x);
				b = max(x, r[index-1]+r[index]+1-x);
			}
			if(maxb < a){
				for(int i = mina; i<=(mina+maxb-1)/2; i++){
					if(i==mina){
						if(reverseCount[mina]%2){
							swap(s[mina-1], s[maxb-1]);
						}
					} else {
						reverseCount[i] += reverseCount[i-1];
						if(reverseCount[i]%2){
							swap(s[i-1],s[maxb-i+mina-1]);
						}
					}
				}
				maxb = INT_MIN;
				mina = INT_MAX;
			}
			maxb = max(maxb,b);
			mina = min(mina,a);
			reverseCount[a]++;
			reverseCount[b]--;
			// cout<<a<<" "<<b<<"\n";
		}
	}
	if(mina!=INT_MAX&&maxb!=INT_MIN){
		for(int i = mina; i<=(mina+maxb)/2; i++){
			if(i==mina){
				if(reverseCount[mina]%2){
					swap(s[mina-1], s[maxb-1]);
				}
			} else {
				reverseCount[i] += reverseCount[i-1];
				if(reverseCount[i]%2){
					swap(s[i-1],s[maxb-i+mina-1]);
				}
			}
		}
		maxb = INT_MIN;
		mina = INT_MAX;
	}
	cout<<s<<"\n";
}
	return 0;
}