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

	string n;
	cin>>n;
	bool flag = 0;
	string prevn = "a";
	int prevSize = n.length();
	while(prevn!=n){
	prevn = n;
	for(int k = prevSize; k>=1; k--){
		if((int)n[n.length()-k]>=53){
			if(k==n.length()){
				for(int i = 0; i<n.length(); i++){
					n[i]  = '0';
				}
				n = "1" + n;
				flag = 1;
				break;
			}
			if(n[n.length()-k-1]==57){
				int j = n.length()-k-1;
				while(j>=0&&n[j]==57){
					j--;
				}
				if(j==-1){
					for(int i = 0; i<n.length(); i++){
						n[i]  = '0';
					}
					n = "1"+n;
					flag = 1;
					break;
				} else {
					for(int i = j+1; i<n.length(); i++){
						n[i] = '0';
					}
					prevSize = k+1;
					n[j]+=1;
					break;
				}
			} else {
				for(int i = n.length()-k; i<n.length(); i++){
						n[i] = '0';
				}
				n[n.length()-k-1]+=1;
				prevSize = k+1;
				break;
			}
		}
	}
	if(flag){
		break;
	}
	}
	cout<<n<<"\n";


}
}