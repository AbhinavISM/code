#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int m;
	cin>>m;
	int ans; 
	if(n>=m-1){
		ans = m;
	} else {
		ans = n+1;
	}
	if(m==1){
		ans = 0;
	}
	cout<<ans<<"\n";
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(i>=m-1){
					cout<<j<<" ";
				} else {
					cout<<(i+j)%m<<" ";
				}
			}
			cout<<"\n";
		}
}
	return 0;
}