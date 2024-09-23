#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int mini = INT64_MAX;
int firstans = 1;
int secondans = 1;
void numswithmindiff(int first, int second, vector<int> &primefactors,int i, int x){
	if(abs(first-second)<mini){
		mini = abs(first-second);
		firstans = first;
		secondans = second;
	}
	if(i>=primefactors.size()) return;
	numswithmindiff(first*primefactors[i], x/(first*primefactors[i]), primefactors, i+1,x);
	numswithmindiff(first, second, primefactors, i+1,x);
}
int32_t main(){
	fast_io;
	int x;
	cin>>x;
	int sex = x;
	vector<int> primefactors;
	for(int i = 2; i*i<=x; i++){
		if(x%i==0){
			int primepower = 1;
				while(x%i==0){
					x = x/i;
					primepower *= i;
				}
				primefactors.push_back(primepower);
		}
	}
	if(x>1) primefactors.push_back(x);
	// for(int pf : primefactors){
	// 	cout<<pf<<" ";
	// }
	if(sex!=1) numswithmindiff(primefactors[0],(sex/primefactors[0]),primefactors,1,sex);
	cout<<firstans<<" "<<secondans<<"\n";
	return 0;
}