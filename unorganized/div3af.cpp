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
	int d;
	cin>>d;
	unordered_set<int> cookieSellers(m);
	int mincookies = 0;
	int removables = 0;
	bool presentBetweend = false;
	int lastCookie = 0;
	int lastitem = 0;
	for(int i = 0; i<m; i++){
		int item;
		cin>>item;
		cookieSellers.insert(item);
		if(item==1){
			mincookies++;
			lastCookie = 1;
			lastitem = 1;
			continue;
		}
		if(item-lastCookie>=d){
			mincookies += (item-lastCookie)/d;
			lastCookie = item;
		}
		if((item%d!=1)&&(item-lastCookie)%d!=0){
			if(presentBetweend){
				mincookies++;
				lastCookie = item;
			}
			removables++;
			presentBetweend = true;
		}
	}
	// for(int i = 1; i<=n; i++){
	// 	cout<<"I";
	// 	if(i==1){
	// 		mincookies++;
	// 		lastCookie = 1;
	// 		continue;
	// 	}
	// 	if(i-lastCookie>=d){
	// 		mincookies++;
	// 		lastCookie = i;
	// 		continue;
	// 	}
	// 	if(cookieSellers.find(i)!=cookieSellers.end()){
	// 		if(presentBetweend){
	// 			mincookies++;
	// 			lastCookie = i;
	// 		}
	// 		removables++;
	// 		presentBetweend = true;
	// 	}
	// }
	cout<<mincookies<<" ";
	cout<<removables<<"\n";
}
	return 0;
}