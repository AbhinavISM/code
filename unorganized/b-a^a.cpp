#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	for(int i = 1; i<=15; i++){
		int temp = 1;
		for(int j = 0; j<i; j++){
			temp *= i;
		}
		if(temp==n){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}