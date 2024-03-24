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
	int k;
	cin>>k;
	if(k==n-1){
		for(int i =1 ; i<=n; i++){
			cout<<i<<" ";
		}
		cout<<"\n";
		continue;
	}
	if(k==0){
		for(int i =n ; i>=1; i--){
			cout<<i<<" ";
		}
		cout<<"\n";
		continue;
	}
	cout<<1<<" ";
	for(int i =2 ; i<=k; i++){
		cout<<i<<" ";
	}
	cout<<n<<" ";
	for(int i = n-1; i>=k+1; i--){
		cout<<i<<" ";
	}
	cout<<"\n";
}
	return 0;
}