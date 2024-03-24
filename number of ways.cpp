#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		sum += item;
	}
	if(sum%3!=0||n<3){
		cout<<0;
		return 0;
	}
	
	return 0;
}