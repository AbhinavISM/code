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
	vector<int> setS;
	int mex=0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(item==mex){
			mex++;
		}
		setS.push_back(item);
	}
	cout<<mex<<"\n";
	cout.flush();
	int y;
	cin>>y;
	while(y!=-1){
		cout<<y<<"\n";
		cout.flush();
		cin>>y;
	}
}
	return 0;
}