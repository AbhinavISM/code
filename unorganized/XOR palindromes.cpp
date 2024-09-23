#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	// fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	string mystr;
	vector<int> array(n);
	vector<int> evens;
	vector<int> odds;
	cin>>mystr;
	for(int i = 0; i<n; i++){
		array[i] = mystr[i];
	}
	int i = 0; int j = n-1;
	if(n%2){
		odds.push_back(1);
	}
	int compulsory = 0;
	while(i<j){
		if(array[i]==array[j]){
			if(evens.size()==0){
				evens.push_back(2);
			} else {
				evens.push_back((*(evens.rbegin())) + 2);
			}
			if(odds.size()!=0){
				odds.push_back((*(odds.rbegin())) + 2);
			}
		} else {
			compulsory++;
		}
		i++;
		j--;
	}
	if(compulsory==0){
		evens.push_back(0);
	}
	set<int> ans;
	ans.insert(compulsory);
	for(int item : evens){
		ans.insert(item+compulsory);
	}
	for(int item : odds){
		ans.insert(item+compulsory);
	}
	vector<bool> finalans(n+1,0);
	for(int i = 0; i<=n; i++){
		if(ans.find(i)!=ans.end()){
			finalans[i] = 1;
		}
	}
	for(int i = 0; i<=n; i++){
		cout<<finalans[i];
	}
	cout<<"\n";
}
	return 0;
}