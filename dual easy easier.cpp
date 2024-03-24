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
	}
	int last = array[0];
	if(allnegative==false){
	for(int i = 1; i<n; i++){
		while(array[i]<last){
			int diff = last-array[i];
			int j = -1;
			int valueToAdd = INT_MAX;
			int maxi = INT_MIN;
			int maxidx = -1;
			for(int k = 0; k<n; k++){
				if(array[k]>maxi){
					maxi = array[k];
					maxidx = k;
				}
				if(array[k]>=diff&&array[k]<=valueToAdd){
					j = k;
					valueToAdd = array[k];
				}
			}
			if(j==-1){
				valueToAdd = maxi;
				j = maxidx;
			}
			ans.push_back({i,j});
			numops++;
			array[i] += valueToAdd;
		}
		last = array[i];
	}
	} else {
		numops = n-1;
		for(int i = n-1; i>0; i--){
			ans.push_back({(i-1),i});
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