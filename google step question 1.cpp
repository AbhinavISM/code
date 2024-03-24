#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<vector<int>> pre(n+1,vector<int>(20,0));
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		a[i] = item;
		int j = 19;
		while(item>0){
			pre[i][j] = item%2;
			item/=2;
			j--;
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<20; j++){
			pre[i][j] += pre[i-1][j];
		}
	}
	int q;
	cin>>q;
	while(q--){
		int indx, val;
		cin>>indx>>val;
		int lo = indx;
		int hi = n;
		int ans = n+1;
		while(hi>=lo){
			int mid = lo + (hi-lo)/2;
			vector<int> binary(20);
			for(int i = 0; i<20; i++){
				binary[i] = pre[mid][i] - pre[indx-1][i];
			}
			int myval = 0;
			for(int i = 19; i>=0; i--){
				if(binary[i]>0){
					myval += (1<<(19-i));
				}
			}
			if(myval>=val){
				ans = min(ans,mid);
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		if(ans==n+1) cout<<-1<<"\n";
		else cout<<ans<<"\n";
	}
}