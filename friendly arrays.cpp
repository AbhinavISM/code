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
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	vector<int> b(m);
	for(int i = 0; i<m; i++){
		int item;
		cin>>item;
		b[i] = item;
	}
	int bor = 0;
	for(int i = 0; i<m; i++){
		bor = bor|b[i];
	}
	int minans = 0;
	int maxans = 0;
	for(int i = 0; i<n; i++){
		minans = minans^a[i];
		a[i] = a[i]|bor;
		maxans =  maxans^a[i];
	}
	if(n%2) cout<<minans<<" "<<maxans<<"\n";
	else cout<<maxans<<" "<<minans<<"\n";
}
	return 0;
}