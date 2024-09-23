#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int binexp(int x, int y){
    int ans = 1;
    while(y>0){
        if(y%2!=0) {
            ans *= x;
            ans = ans;
        }
        x = (x*x);
        y = y/2;
    }
    return ans;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int a;
	cin>>a;
	int cnt = 0;
	while(a!=0){
		if(a%2){
			cnt++;
		}
		a/=2;
	}
	cout<<binexp(2, cnt)<<"\n";
}
	return 0;
}