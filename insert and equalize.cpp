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
	vector<int> array;
	set<int> bs;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array.push_back(item);
		bs.insert(item);
	}
	if(n==1){
		cout<<1<<"\n";
		continue;
	}
	sort(array.begin(), array.end());
	int gcd = array[1] - array[0];
	for(int i = 2; i<n; i++){
		gcd = __gcd(gcd, array[i] - array[i-1]);
	}

	int factor = 1;
	int x;
	while(1){
			if(bs.find(array[n-1] - gcd*factor)==bs.end()){
				x = array[n-1] - gcd*factor;
				break;
			}
			factor+=1;
	}
	
	// int x = -1;
	// for(int i = n-2; i>=0; i--){
	// 	if((array[i+1] - array[i])>gcd){
	// 		x = array[i+1] - gcd;
	// 		break;
	// 	}
	// }
	// if(x==-1){
	// 	x = array[0] - gcd;
	// }

	array.push_back(x);
	sort(array.begin(), array.end());
	int ans = 0;
	int maxele = array[n];
	for(int ele : array){
		ans += (maxele - ele)/gcd;
	}
	cout<<ans<<"\n";
}
	return 0;
}