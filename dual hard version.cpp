#include<bits/stdc++.h>
// #define int long long
// #define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<int> array(n);
	bool allnegative = true;
	int maxele = INT_MIN;
	int maxeleidx = -1;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
		if(array[i]>maxele){
			maxele = array[i];
			maxeleidx = i;
		}
		if(item>0){
			allnegative = false;
		}
	}
	int numops = 0;
	vector<pair<int, int>> ans;
	if(allnegative==false){
		while(array[maxeleidx]<20){
			array[maxeleidx] += array[maxeleidx];
			ans.push_back({maxeleidx,maxeleidx});
			numops++;
		}
		for(int i = 0; i<n; i++){
			if(i!=maxeleidx&&array[i]<0){
				array[i]+=array[maxeleidx];
				ans.push_back({i,maxeleidx});
				numops++;
			}
		}
	}
	if(allnegative==false){
		for(int i = 0; i<n-1; i++){
			if(array[i+1]<array[i]) {
				ans.push_back({(i+1),i});
				array[i+1]+=array[i];
				numops++;
			}
		}
	} else {
		for(int i = n-1; i>0; i--){
			if(array[i-1]>array[i]){
			 ans.push_back({(i-1),i});
			 array[i-1]+=array[i];
			 numops++;
			}
		}
	}	
	cout<<numops<<"\n";
	for(auto a : ans){
		cout<<a.first+1<<" "<<a.second+1<<"\n";
	}
	cout<<"\n";
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
}
	return 0;
}