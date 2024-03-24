#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	multiset<pair<int,int>> ss;
	for(int i = 0; i<=2*n-1; i++){
		int temp;
		cin>>temp;
		ss.insert({temp,(i%n)+1});
	}
	int mod;
	cin>>mod;
	for(auto it : ss){
		cout<<it.first<<" "<<it.second<<"\n";
	}
	return 0;
}