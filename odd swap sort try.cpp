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
		stack<int> array;
		stack<int> temp;
		bool flag = true;
		for(int i = 0; i<n; i++){
			int item;
			cin>>item;
			if(array.size()==0||item>=array.top()) {
				array.push(item);
			}
			else {
				while(temp.size()>0&&item>temp.top()){
					if(temp.top()%2==item%2){flag = false;}
					array.push(temp.top());
					temp.pop();
				}
				while(array.size()>0&&item<array.top()){
					if(array.top()%2==item%2){flag = false;}
					temp.push(array.top());
					array.pop();
				}
				array.push(item);
			}
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
		
	}
		return 0;
	}