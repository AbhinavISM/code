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
	string array = "";
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array += to_string(item);
	}
	cout<<array<<"\n";
	// int maxi= -1;
	// int maxidx = -1;
	// for(int i = 0; i<n; i++){
	// 	if(array[i]>maxi){
	// 		maxi = array[i];
	// 		maxidx = i;
	// 	}
	// }
	// if(maxidx==0){
	// 	maxi= -1;
	// 	maxidx = -1;
	// 	for(int i = 1; i<n; i++){
	// 	if(array[i]>maxi){
	// 		maxi = array[i];
	// 		maxidx = i;
	// 	}
	// 	string largestPermuation(n,'0');
	// 	for(int i = maxidx-1; i>=1; i--){
	// 		string thisstring = "";
	// 		thisstring += array.substr(maxidx,n-maxidx);
	// 		string toreverse = array.substr(i, maxidx-i);
	// 		reverse(toreverse.begin(), toreverse.end());
	// 		thisstring += toreverse;
	// 		thisstring += array.substr(0,i);
	// 		// int cmp = strcmp(largestPermuation, thisstring);
	// 		if(cmp<0){
	// 			largestPermuation = thisstring;
	// 		}
	// 	}
	// }
	// }
}
	return 0;
}