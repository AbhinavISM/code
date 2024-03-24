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
	int sum = 0;
	for(int i = 0; i<n-1; i++){
		int item;
		cin>>item;
		sum += item;
	}
	cout<<(-1*sum)<<"\n";
}
	return 0;
}