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
	int mindiff = INT64_MAX;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		if(i!=0){
			if(array[i]<array[i-1]){
				mindiff = -2;
			}
			mindiff = min(mindiff, abs(array[i]-array[i-1]));
		}
	}
	cout<<(mindiff/2) + 1<<"\n";
}
	return 0;
}