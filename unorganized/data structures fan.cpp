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
	vector<int> array(n+1,0);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	string s;
	cin>>s;

	vector<int> prexor(n+1,0);
	int ans = 0;
	for(int i = 1; i<=n; i++){
		prexor[i] = prexor[i-1]^array[i];
		if(s[i-1]=='1') ans = ans^array[i];
	}
	// for(int i = 0; i<=n; i++){
	// 	cout<<prexor[i]<<" ";
	// }


	int q;
	cin>>q;
	while(q--){
		int queryType;
		cin>>queryType;
		if(queryType==1){
			int l,r;
			cin>>l>>r;
			int subxor = prexor[r]^prexor[l-1];
			ans = ans^subxor;
		} else {
			int g;
			cin>>g;
			if(g==1){
				cout<<ans<<" ";
			} else {
				cout<<(ans^prexor[n])<<" ";
			}
		}
	}
	cout<<"\n";
}
	return 0;
}