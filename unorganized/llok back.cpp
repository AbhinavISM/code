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
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	int ans = 0;
	int last = 0;
	int twopow = 1;
	int power = 0;
	int maxpower = 0;
	while(twopow<array[0]){
			twopow*=2;
			power++;
	}
	last = power;
	maxpower = max(maxpower, power);
	for(int i = 1; i<n; i++){
		twopow = 1;
		power = 0;
		while(twopow<=array[i]){
			twopow*=2;
			power++;
		}
		power--;
		cout<<last<<" "<<power<<"\n";
		if(last>power){ans+=last-power;}
		maxpower = max(maxpower, power);
		last = max(power, maxpower);
	}
	cout<<ans<<"\n";
}
	return 0;
}