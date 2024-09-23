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
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	int i = 1;
	int j = n;
	int deep = 0;
	int wierd = true;
	while(i<j){
		if(array[i]!=i||array[j]!=j){
			if(array[i]+array[j]!=n+1){
				wierd = false;
			}
			deep = i;
		}
		i++;
		j--;
	}
	if(wierd){
		if(deep==0){
			cout<<deep<<"\n";
		} else {
		cout<<deep-1<<"\n";			
		}
	} else {
		if(n%2) cout<<deep<<"\n";
		else cout<<deep-1<<"\n";
	}
}
	return 0;
}