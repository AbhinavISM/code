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
	int a = n/m;
	int l = m%10;
	if(l==0){
		cout<<0;
	} else if(l==1||l==3||l==7||l==9){
		int ans = 0;
		ans += (a/10)*(45);
		int temp = l;
		for(int i = 1; i<=a%10; i++){
			ans += (temp%10);
			temp += l;
		}
		cout<<ans;
	} else if(l==2||l==4||l==6||l==8){
		int ans = 0;
		ans += (a/5)*(20);
		int temp = l;
		for(int i = 1; i<=a%5; i++){
			ans += (temp%10);
			temp += l;
		}
		cout<<ans;
	} else {
		int ans = 0;
		ans += (a/2)*(5);
		int temp = l;
		for(int i = 1; i<=a%2; i++){
			ans += (temp%10);
			temp += l;
		}
		cout<<ans;
	}
	cout<<"\n";
}
	return 0;
}