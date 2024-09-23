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
	vector<int> array(n-1);
	int mys;
	int mye;
	cin>>mys;
	cin>>mye;
	int maxe = INT_MIN;
	for(int i = 0; i<n-1; i++){
		int s;
		int e;
		cin>>s;
		cin>>e;
		if(s>=mys){
			maxe = max(maxe,e);
		}
	}
	if(maxe>=mye){
		cout<<-1;
	} else {
		cout<<mys;
	}
	cout<<"\n";
}
	return 0;
}