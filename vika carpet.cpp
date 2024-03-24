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
	int m;
	cin>>m;
	vector<string> array;
	bool foundV = false;
	bool foundI = false;
	bool foundK = false;
	bool foundA = false;
	for(int i = 0; i<n; i++){
		string s;
		cin>>s;
		array.push_back(s);
	}
	for(int i= 0; i<m; i++){
		for(int j = 0; j<n; j++){
			char item = array[j][i];
			if(!foundV){
				if(item=='v'){
					foundV = true;
					break;
				}
					continue;

			} else if(!foundI){
				if(item=='i'){
					foundI = true;
					break;
				}
					continue;
			} else if(!foundK){
				if(item=='k'){
					foundK = true;
					break;
				}
					continue;

			} else if(!foundA){
				if(item=='a'){
					foundA = true;
					break;
				}
					continue;
				
			}
			// array[i].push_back(item);
		}
	}
	if(foundV&&foundI&&foundK&&foundA){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}

}
	return 0;
}