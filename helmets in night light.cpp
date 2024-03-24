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
	int p;
	cin>>p;
	vector<int> sharepower(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		sharepower[i] = item;
	}
	vector<pair<int,int>> sharecost(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		sharecost[i].first = item;
		sharecost[i].second = sharepower[i];
	}
	sort(sharecost.begin(), sharecost.end());
	int cost = 0;
	int count = n;
	vector<bool> told(n,false);
	int lasttold = 0;
	for(int i = 0; i<n&&count>0; i++){
		if(sharecost[i].first<=p){
			int thissp = sharecost[i].second;
			int thissc = sharecost[i].first;
			if(count>thissp){
				if(told[i]==false) {
					cost += (p + thissp*thissc);
					count -= (thissp+1);
					for(int j = lasttold; j<lasttold+thissp+1&&j<n; j++){
						told[j] = true;
					}
					lasttold += thissp+1;
				}
				else {
					cost += (thissp*thissc);
					count -= (thissp);
					for(int j = lasttold; j<lasttold+thissp&&j<n; j++){
						told[j] = true;
					}
					lasttold += thissp;
				}
			}
			else {
				if(told[i]==false) cost += (p + (count-1)*thissc);
				else cost += ((count)*thissc);
				count = 0;
			}
		}
	}
	if(count>0){
	    cost += count*p;
	}
	cout<<cost<<"\n";
}
	return 0;
}