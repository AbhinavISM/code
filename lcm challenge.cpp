#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int lcm(int x, int y){
	return (x*y)/__gcd(x,y);
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int sub = n*(n-1);
	int ans1 = 1;
	for(int i = 1; i<=n; i++){
		ans1 = max(ans1, lcm(sub, i));
	}
	sub = (n-1)*(n-2);
	int ans2 = 1;
	for(int i = 1; i<=n; i++){
		ans2 = max(ans2, lcm(sub, i));
	}
	cout<<max(ans1,ans2);
	return 0;
}