#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n,0);
	int ans = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	for(int i = 1; i<n; i++){
		if(array[i-1]>array[i]){ans += array[i-1]-array[i];
		array[i] = array[i-1];
	}
	}
	cout<<ans;
	return 0;
}