#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
// int binsrch(vector<int> &array, int x){
// 	int hi = array.size()-1;
// 	int lo = 0;
// 	for()
// }
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	for(int i = 1; i<n; i++){
		array[i] += array[i-1];
	}
	int m;
	cin>>m;
	for(int i = 0; i<m; i++){
		int item;
		cin>>item;
		auto it = lower_bound(array.begin(), array.end(), item);
		cout<<it-array.begin()+1<<"\n";
		// cout<<binsrch(array, item)<<"\n";
	}
	return 0;
}