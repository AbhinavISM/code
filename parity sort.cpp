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
	int k;
	cin>>k;
	vector<int> array(n+1,0);
	int firstItem;
	int lastItem;
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
		if(i==1){
			firstItem = item;
		}
		if(i==n){
			lastItem = item;
		}
	}
	int lastFirst;
	int firstCount = 0;
	for(int i = 1; i<=n; i++){
		if(firstCount==k){
			break;
		}
		if(array[i]==firstItem){
			lastFirst = i;
			firstCount++;
		}
	}
	int firstLast;
	int lastCount = 0;
	for(int i = n; i>=1; i--){
		if(lastCount==k){
			break;
		}
		if(array[i]==lastItem){
			firstLast = i;
			lastCount++;
		}
	}
	if(firstItem==lastItem&&firstCount==k){
		cout<<"YES";
	}
	else if(firstCount==k&&lastCount==k&&lastFirst<firstLast){
		cout<<"YES";
	} else {
		cout<<"NO";
	}
	cout<<"\n";
}
	return 0;
}