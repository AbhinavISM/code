#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
long long power(long long A, long long B)
{
    if (B == 0)
        return 1;
 
    long long res = power(A, B / 2);
 
    if (B % 2)
        return res * res * A;
    else
        return res * res;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int a,b,l;
	cin>>a>>b>>l;
	int apow = 0;
	int bpow = 0;
	set<int> k;
	while(power(a,apow)<=l){
		apow++;
	}
	while(power(b,bpow)<=l){
		bpow++;
	}
	apow--;
	bpow--;
	// cout<<apow<<" "<<bpow<<"\n";
	for(int i = 0; i<=apow; i++){
		for(int j = 0; j<=bpow; j++){
			int apoweri = power(a,i);
			int bpowerj = power(b,j);
			// cout<<(apoweri*bpowerj)<<" ";
			if(apoweri*bpowerj<=l){
				if(l%(apoweri*bpowerj)==0){
					k.insert(l/(apoweri*bpowerj));
				}
			}
		}
	}
	// cout<<"\n";
	cout<<k.size()<<"\n";
}
	return 0;
}