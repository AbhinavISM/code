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
	vector<int> array(n+1);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	int ans = 0;
	int oneseaya = -1;
	for(int i = n-2; i>=0; i--){
		if(array[i]>array[i+1]){
			if(array[i]==1){
				oneseaya = i;
				break;
			}
			int a = array[i] - array[i+1];
			int b = array[i]/2;
			int x = max(a,b);
			array[i+1] = array[i] - x;
			array[i] = x;
			i++;
			ans++;
		}
	}
	if(oneseaya==-1){
		cout<<ans<<"\n";		
	} else {
		for(int i = 0; i<oneseaya; i++){
			ans += array[i] - 1;
		}
		cout<<ans<<"\n";
	}
}
	return 0;
}