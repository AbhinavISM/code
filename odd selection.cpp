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
	int x;
	cin>>x;
	int odd = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(item%2) odd++;
	}
	int even = n-odd;
	if(odd==0){
		cout<<"NO\n";
		continue;
	} else if(x%2==0&&odd>=x){
		x-=(x-1);
		x-=even;
	} else{
		if(odd%2){
			x-=(odd);
		} else {
			x-=(odd-1);
		}
		x -= even;
	}
	if(x<=0){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}