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
	int maxLandings = 0;
	vector<int> jumphere(n+1,0);
	vector<int> frequency(n+1,0);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(item>n){ continue; }
		frequency[item]++;
	}
	for(int i = 1; i<=n; i++){
		int temp = i;
		while(temp<=n&&frequency[i]!=0){
			jumphere[temp]+=frequency[i];
			temp += i;
		}
	}
	for(int i = 1; i<=n; i++){
		maxLandings = max(maxLandings, jumphere[i]);
	}
	cout<<maxLandings<<"\n";
}
	return 0;
}