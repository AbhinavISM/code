#include<bits/stdc++.h>
// #define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int numdivisors(int a){
	if(a==1){
		return 1;
	}
	int numdiv = 2;
	for(int i = 2; i*i<=a; i++){
		if(a%i==0){
			if(i*i==a) numdiv++;
			else numdiv+=2;
		}
	}
	return numdiv;
}
int32_t main(){
	fast_io;
	int a;
	cin>>a;
	int b;
	cin>>b;
	int n;
	cin>>n;
	vector<bool> numdivisors(100001,true);
	numdivisors[0] = false;
	numdivisors[1] = false;
	for(int i = 2; i*i<100001; i++){
		if(numdivisors[i]){
			for(int j = i*i; j<100001; j+=i){
				numdivisors[j] = false;
			}
		}
	}
	int ans = 0;
	for(int i = a; i<=b; i++){
		int temp = i;
		int thistotaldiv = 1;
		for(int j = 2; j*j <= i; j++){
		if(numdivisors[j]){
			int thispower = 0;
			while(temp%j==0){
				thispower++;
				temp = temp/j;
			}
			thistotaldiv *= (thispower+1);
			// cout<<"number: "<<i<<" prime: "<<j<<" power: "<<thispower<<"\n";
		}
		}
		if(temp!=1){
			thistotaldiv*=2;
		}
		if(thistotaldiv==1&&i!=1) thistotaldiv = 2;
		if(thistotaldiv==n) ans++;
	}
	cout<<ans;
	return 0;
}