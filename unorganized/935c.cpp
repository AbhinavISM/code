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
	vector<int> zs(n,0);
	vector<int> os(n,0);
	string a;
	cin>>a;
	for(int i = 0; i<n; i++){
		if(a[i]=='0'){
			zs[i] = 1;
		} else {
			os[i] = 1;
		}
	}
	for(int i = 1; i<n; i++){
		zs[i] += zs[i-1];
		os[i] += os[i-1];
	}
	// cout<<ceil((double)3/2);
	int ans=INT_MAX;
	if(os[n-1]>=ceil(((double)(n))/2)){
				ans=0;
	}
	for (int i = 0; i < n; ++i)
	{
		int temp=ceil(((double)(i+1))/2);
		int temp2=ceil(((double)(n-i-1))/2);
		if(zs[i]>=temp && os[n-1]-os[i]>=temp2){
			if(abs((ans)-(double)n/2)>abs((i+1)-(double)n/2)){
				ans=i+1;
			}
		}
	}
	
	cout<<ans<<endl;
}
	return 0;
}