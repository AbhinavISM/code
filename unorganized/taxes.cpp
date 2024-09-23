#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	if(n==2){
		cout<<1;
		return 0;
	}
	if(n%2==0){
		cout<<2;
		return 0;
	}
	vector<bool> isPrime(100001, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i*i<100001; i++){	
		if(isPrime[i]){
			for(int j = i*i; j<=100001; j+=i){
				isPrime[j] = false;
			}
		}
	}
	vector<int> primes;
	for(int i = 2; i<100001; i++){
		if(isPrime[i]){
			primes.push_back(i);
		}
	}
	if(n<=100000){
		if(isPrime[n]){
			cout<<1;
			return 0;
		}
	}
	int temp = n;
	for(int p : primes){
		if(p*p>temp){
			break;
		}
		if(temp%p==0){
			while(temp%p==0){
				temp/=p;
			}
		}
	}
	if(temp==n){
		cout<<1;
		return 0;
	}
	n = n-2;
	temp = n;
	for(int p : primes){
		if(p*p>temp){
			break;
		}
		if(temp%p==0){
			while(temp%p==0){
				temp/=p;
			}
		}
	}
	if(temp==n){
		cout<<2;
		return 0;
	} else {
		cout<<3;
		return 0;
	}
	return 0;
}