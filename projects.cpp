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
	if(first.b!=second.b) return first.b<second.b;
	if(first.a!=second.a) return first.a<second.a;
	else return first.p<second.p;
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
	dp[0] = array[0].p;
	for(int i = 1; i<n; i++){
		int lo = 0;
		int hi = i-1;
		int ans = -1;
		while(lo<=hi){
			int mid = lo + (hi-lo)/2;
			if(array[mid].b<array[i].a){
				ans = max(ans, mid);
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if(ans!=-1) dp[i] = max(dp[ans] + array[i].p, dp[i-1]);
		else dp[i] = max(array[i].p, dp[i-1]);
	}
	cout<<dp[n-1];
	return 0;
}