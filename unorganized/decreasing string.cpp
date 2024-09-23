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
	string s1;
	cin>>s1;
	int pos;
	cin>>pos;
	int n = s1.length();
	int curr = n;
	int round = 0;
	for(int i = 0; i<n; i++){
		if(pos>curr){
			pos -= curr;
			curr -= 1;
			round++;
		}
	}
	// cout<<pos<<" ";
	stack<char> temp;
	for(int i = 0, r = 0; i<n; i++){
		if(temp.empty()){
			temp.push(s1[i]);
		} else {
			while((!temp.empty())&&temp.top()>s1[i]&&r<round){
				temp.pop();
				r++;
			}
			temp.push(s1[i]);
		}
		if(i==n-1&&r<round){
			while(r<round){
				temp.pop();
				r++;
			}
		}
	}	
	vector<char> vc(temp.size());
	// cout<<vc.size();
	for(int i = vc.size()-1; i>=0; i--){
		vc[i] = temp.top();
		temp.pop();
	}
	cout<<vc[pos-1];
// 	cout<<"dfde";
}
	return 0;
}