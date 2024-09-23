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
	int k;
	cin>>k;
	int H;
	cin>>H;

	vector<int> heights;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		heights.push_back(item);
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(abs(H-heights[i])>0&&abs(H-heights[i])%k==0&&abs(H-heights[i])/k<m){
			ans++;
		}
	}
	cout<<ans<<"\n";

}
}