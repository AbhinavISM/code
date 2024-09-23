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
	vector<vector<int>> array;
	int f;
	cin>>f;
	vector<int> vi;
	int j = 0;
	vi.push_back(f);
	array.push_back(vi);
	int ppar = abs(array[0][0])%2;
	for(int i = 1; i<n; i++){
		int item;
		cin>>item;
		if(ppar!=abs(item)%2){
			array[j].push_back(item);
			ppar = abs(item)%2;
		} else {
			j++;
			vector<int> temp;
			temp.push_back(item);
			array.push_back(temp);
		}
	}
	int ans = INT_MIN;
	for(auto it : array){
		int maxsum = INT_MIN;
		int netsum = 0;
		for(int ele : it){
			netsum+=ele;
			maxsum = max(netsum, maxsum);
			if(netsum<0){
				netsum = 0;
			}
		}
		ans = max(maxsum, ans);
	}
	cout<<ans<<"\n";
}
	return 0;
}