#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int ncr(int n,int r){
	int sum = 1;
	for(int i = 1; i <= r; i++){
	    sum = sum * (n - r + i) / i;
	}
	return sum;
}
int f(int k, int n, int b, int x, vector<int>&c){
	int ans = 0;
	for(int i = 0; i<n; i++){
		int each = c[i]/k;
		if(c[i]%k==0){
			ans += b*each*each*(ncr(k,2));
		} else {
			int each2 = c[i]/k + 1;
			int each2cnt = c[i]%k;
			int eachcnt = k - each2cnt;
			ans += b*each*each*(ncr(eachcnt,2));
			ans += b*each2*each2*(ncr(each2cnt,2));
			ans += b*each*each2*(ncr(eachcnt,1)*ncr(each2cnt,1));
		}
	}
	ans -= (k-1)*x;
	return ans;
}
int ternary_search(int l, int r, int n, int b, int x, vector<int>&c) {
    while (r - l > 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = f(m1,n,b,x,c);      //evaluates the function at m1
        int f2 = f(m2,n,b,x,c);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    //return the maximum of f(x) in [l, r]
    int ans = f(l,n,b,x,c);
    for(int i = l+1; i<=r; i++){
    	ans = max(ans, f(i,n,b,x,c));
    }
    return ans;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,b,x;
	cin>>n>>b>>x;
	vector<int> c(n);
	int lsize = 1;
	int msize = -1;
	for(int i = 0; i<n; i++){
		cin>>c[i];
		msize = max(msize,c[i]);
	}
	cout<<ternary_search(lsize,msize,n,b,x,c)<<"\n";
}
	return 0;
}