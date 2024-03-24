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
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	if(k==2){
		bool allodd = true;
		for(int i = 0; i<n; i++){
			if(array[i]%2==0) allodd = false;
		}
		if(allodd){
			cout<<1<<"\n";
		} else {
			cout<<0<<"\n";
		}
	}
	if(k==3){
		int closest = INT_MAX;
		for(int i = 0; i<n; i++){
			if(3-array[i]>=0){closest = min(3-array[i], closest);}
			if(6-array[i]>=0){closest = min(6-array[i], closest);}
			if(9-array[i]>=0){closest = min(9-array[i], closest);}
			if(12-array[i]>=0){closest = min(12-array[i], closest);}
		}
		cout<<closest<<"\n";
	}
	if(k==5){
		int closest = INT_MAX;
		for(int i = 0; i<n; i++){
			if(5-array[i]>=0){closest = min(5-array[i], closest);}
			if(10-array[i]>=0){closest = min(10-array[i], closest);}
		}
		cout<<closest<<"\n";
	}
	if(k==4){
		int closest = INT_MAX;
		for(int i = 0; i<n; i++){
			if(4-array[i]>=0){closest = min(4-array[i], closest);}
			if(8-array[i]>=0){closest = min(8-array[i], closest);}
			if(12-array[i]>=0){closest = min(12-array[i], closest);}
		}
		if(n>=2){
			int evencnt = 0;
			for(int i = 0; i<n; i++){
				if(array[i]%2==0) evencnt++;
			}
			if(evencnt>=2) {closest = 0;}
			if(evencnt==1) {closest = min(closest, 1ll);}
			if(evencnt==0) {closest = min(closest, 2ll);}
		}
		cout<<closest<<"\n";
	}
}
	return 0;
}