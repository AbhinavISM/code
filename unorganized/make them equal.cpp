#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	set<int> differences;
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			if(array[j]-array[i]!=0) differences.insert(abs(array[j]-array[i]));
		}
	}
	if(differences.size()>=3){
		cout<<"-1";
	} else if(differences.size()==2){
		auto it = differences.begin();
		int a = *(it);
		it++;
		int b = *(it);
		if(b==2*a){
			cout<<a;
		} else {
			cout<<"-1";
		}
	} else if(differences.size()==1){
		auto it = differences.begin();
		int a = *(it);
		if(a%2){
			cout<<a;
		} else {
			cout<<a/2;
		}
	} else {
		cout<<0;
	}
	return 0;
}