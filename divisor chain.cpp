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
	int temp = n;
	std::vector<bool> bits;
	std::vector<int> ans;
	ans.push_back(n);
	while(temp){
		bits.push_back(temp%2);
		temp = temp/2;
	}
	temp = 1;
	for(int i = 0; i<bits.size()-1; i++){
		if(bits[i]){
			ans.push_back(n-temp);
			n = n - temp;
		}
		temp*=2;
	}
	temp = temp/2;
	while(temp){
		ans.push_back(temp);
		temp = temp/2;
	}
	cout<<ans.size()<<"\n";
	for(int it : ans){
		cout<<it<<" ";
	}
	cout<<"\n";
}
	return 0;
}