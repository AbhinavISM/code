#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int> a(n);
	int first1;
	int last1;
	bool firstfound = false;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		if(item==1&&(!firstfound)){
			firstfound = true;
			first1 = i;
			last1 = i;
		}
		if(item==1){
			last1 = i;
		}
	}
	int ans = 0;
	for(int i = last1; i>=first1; i--){
		if(a[i]==1){
			for(int j = i-1; j>=first1; j--){
				if(a[j]==0){
					a[j] = 1;
					ans++;
				}
			}		
		}
	}
	// int onecnt = 0;
	// int zerocnt = 0;
	// for(int i = first1; i<=last1; i++){
	// 	if(a[i]==1){
	// 		onecnt++;
	// 	} else {
	// 		zerocnt++;
	// 	}
	// }
	// int ans = 0;
	// for(int i = first1; i<first1 + onecnt; i++){
	// 	if(a[i]==0){
	// 		ans++;
	// 	}
	// }
	cout<<ans<<"\n";
	// cout<<onecnt<<" ";
	// if(zerocnt==0){
	// 	cout<<0<<"\n";
	// } else {
	// 	int ans = 0;
	// 	int badcnt = 0;
	// 	for(int i = first1; i<=last1&&onecnt>0; i++){
	// 		if(a[i]==1&&badcnt==0){
	// 			onecnt--;
	// 		} else if(a[i]==1){
	// 			badcnt--;
	// 			onecnt--;
	// 			ans++;
	// 		} else {
	// 			onecnt--;
	// 			ans++;
	// 			badcnt++;
	// 		}
	// 	}
	// 	cout<<ans<<"\n";
	// }
}
	return 0;
}