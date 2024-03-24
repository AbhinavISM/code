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
	vector<int> setCount(30,0);
	for(int i = 0; i<n; i++){
		int item = array[i];
		int bitnum = 0;
		while(item!=0){
			if(item%2){
				setCount[bitnum]++;
			}
			item/=2;
			bitnum++;
		}
	}
	for(int i = 1; i<=n; i++){
		int alldivided = true;
		for(int count : setCount){
			if(count%i!=0){
				alldivided = false;
			}
		}
		if(alldivided){
			cout<<i<<" ";
		}
	}
	cout<<"\n";
}
	return 0;
}