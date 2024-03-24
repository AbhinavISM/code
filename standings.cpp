#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool betterCmp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
	int af = a.first.first*(b.first.first+b.first.second);
	int bf = b.first.first*(a.first.first+a.first.second);
	if(af>bf){
		return true;
	} else if(af==bf){
		return a.second<b.second;
	} else {
		return false;
	}
}

int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<pair<pair<int,int>,int>> array(n);
	for(int i = 0; i<n; i++){
		ld heads;
		ld tails;
		cin>>heads;
		cin>>tails;
		array[i] = make_pair(make_pair(heads,tails), i);
	}
	sort(array.begin(), array.end(),betterCmp);
	for(int i = 0; i<n; i++){
		cout<<array[i].second+1<<" ";
	}
	return 0;
}