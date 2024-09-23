#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int x;
int mini = INT_MAX;
int firstans = 1;
int secondans = 1;
void numswithmindiff(int first, int second, vector<int> &primefactors,int i){
	if(abs(first-second)<mini){
		mini = abs(first-second);
		firstans = first;
		secondans = second;
	}
	if(i==primefactors.size()) return;
	numswithmindiff(first*primefactors[i], x/(first*primefactors[i]), primefactors, i+1);
	numswithmindiff(first, second, primefactors, i+1);
}
int32_t main(){
	fast_io;
	vector<bool> isPrime(1000001,true);
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i = 2; i*i<=1000000; i++){
		if(isPrime[i]){
			for(int j = i*i; j<=1000000; j+=i){
				isPrime[j] = false;
			}
		}
	}
	cin>>x;
	vector<int> primefactors;
	for(int i = 2; i*i<=x; i++){
		if(x%i==0){
			int temp = x;
			int primepower = 1;
			if(isPrime[i]){
				while(temp%i==0){
					temp = temp/i;
					primepower *= i;
				}
				primefactors.push_back(primepower);
			}
			if(i*i!=x){
				temp = x;
				primepower = 1;
				if(isPrime[x/i]){
					while(temp%(x/i)==0){
						temp = temp/(x/i);
						primepower *= (x/i);
					}
					primefactors.push_back(primepower);
				}
			}
		}
	}
	int first = 1;
	int second = 1;
	// for(int i = 0; i<primefactors.size(); i++){
		// for(int j = i; j<primefactors.size(); j++){
			// cout<<primefactors[i]<<" ";
		// }
	// }
	numswithmindiff(primefactors[0],(x/primefactors[0]),primefactors,1);
	cout<<firstans<<" "<<secondans<<"\n";
	return 0;
}