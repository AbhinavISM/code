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
	set<int> array;
	multiset<int> marray;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array.insert(item);
		marray.insert(item);
	}
	if(array.size()>2){
		cout<<"NO\n";
	} else if(array.size()==1){
		cout<<"YES\n";
	} else {
		auto it = array.begin();
		int acnt = marray.count((*it));
		it++;
		int bcnt = marray.count((*it));
		if(n%2==0&&acnt==bcnt){
			cout<<"YES\n";
		} else if(n%2==1&&((acnt==bcnt+1)||(bcnt==acnt+1))){
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
}
	return 0;
}