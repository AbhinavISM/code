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
	int mini = INT_MAX;
	int minIdx = -1;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		if(mini > item){
			mini = item;
			minIdx = i;
		}
	}
	bool sorted = true;
	for(int i = minIdx+1; i<n; i++){
		if(array[i]<array[i-1]){
			sorted = false;
		}
	}
	if(sorted){
		cout<<minIdx<<"\n";
	} else {
		cout<<-1<<"\n";
	}
}
	return 0;
}