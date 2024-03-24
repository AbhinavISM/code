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
	int x;
	cin>>x;
	queue<int> s1;
	queue<int> s2;
	queue<int> s3;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		s1.push(item);
	}
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		s2.push(item);
	}
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		s3.push(item);
	}
	bool one = true;
	bool two = true;
	bool three = true;
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(one){
			for(int j = 0; j<30; j++){
				if(((s1.front()&(1<<j))!=0)&&((x&(1<<j))==0)){
					one = false;
				}
			}
			if(one){
					ans = ans|s1.front();
					// cout<<ans<<" ";
					s1.pop();
			}
		}
		if(two){
			for(int j = 0; j<30; j++){
				if(((s2.front()&(1<<j))!=0)&&((x&(1<<j))==0)){
					two = false;
				}
			}
			if(two){
					ans = ans|s2.front();
					// cout<<ans<<" ";

					s2.pop();
			}
		}
		if(three){
			for(int j = 0; j<30; j++){
				if(((s3.front()&(1<<j))!=0)&&((x&(1<<j))==0)){
					three = false;
				}
			}
			if(three){
					ans = ans|s3.front();
					// cout<<ans<<" ";
					
					s3.pop();
			}
		}
	}
	if(ans==x){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}