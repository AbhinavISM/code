#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;

int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n+2);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	multiset<int> ans;
	ans.insert(array[1]);
	for(int i = 2; i<=n; i++){
		if(ans.lower_bound(array[i])!=ans.end()){
			ans.erase(ans.lower_bound(array[i]));
		}
		ans.insert(array[i]);
	}
	cout<<ans.size();
	return 0;
}