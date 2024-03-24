#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct project {
	int a;
	int b;
	int p;
};
bool cmp(project &first, project &second){
	if(first.a==second.a){
		if(first.b<=second.b){
			return true;
		} else {
			return false;
		}
	}
	if(first.a<second.a){
		return true;
	} else {
		return false;
	}
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<project> array(n);
	for(int i = 0; i<n; i++){
		int a,b,p;
		cin>>a>>b>>p;
		array[i] = project();
		array[i].a = a;
		array[i].b = b;
		array[i].p = p;
	}
	sort(array.begin(), array.end(), cmp);
	vector<int> dp(n+1,0);
	for(int i = n-1; i>=0; i--){
		int lo = i+1;
		int hi = n-1;
		int ans = n;
		while(lo<=hi){
			int mid = lo + (hi-lo)/2;
			if(array[mid].a>array[i].b){
				ans = min(ans, mid);
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		dp[i] = max(dp[ans] + array[i].p, dp[i+1]);
	}
	cout<<dp[0];
	return 0;
}