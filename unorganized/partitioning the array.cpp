#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	if(n==1){
		cout<<1<<"\n";
		continue;
	}
	int ans = 0;
	for(int i = 1; i*i<=n; i++){
		if(n%i==0){
			int d = i;
			int gcd = 0;
			for(int j = 1; j<=d; j++){
				for(int k = j+d; k<=n; k+=d){
					if(abs(a[k]-a[k-d])>0){
						gcd = __gcd(gcd,abs(a[k]-a[k-d]));
					}
				}
			}
			if(gcd!=1){
				ans++;
			}
			if((d*d!=n)&&(d!=1)){
				d = n/d;
				gcd = 0;
				for(int j = 1; j<=d; j++){
					for(int k = j+d; k<=n; k+=d){
						if(abs(a[k]-a[k-d])>0){
							gcd = __gcd(gcd,abs(a[k]-a[k-d]));
						}
					}
				}
				if(gcd!=1){
					ans++;
				}
			}
		}
	}
	cout<<ans+1<<"\n";
}
	return 0;
}