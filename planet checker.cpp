#include<iostream>
using namespace std;
int32_t main(){
	int n;
	cin>>n;
	int as = 0, au = 0, bs = 0, bu = 0;
	while(n--){
		int t,x,y;
		cin>>t>>x>>y;
		if(t==1){
			as+=x;
			au+=y;
		} else {
			bs+=x;
			bu+=y;
		}
	}
	cout<<((as>=au)?"LIVE\n":"DEAD\n");
	cout<<((bs>=bu)?"LIVE":"DEAD");
	return 0;
}