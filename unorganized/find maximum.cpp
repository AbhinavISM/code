#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int allsum = 0;
int allonesum = 0;
int solve(vector<int> &array, string &mbinary, int n, int i){
	if(i==n){
		return 0;
	}
	allsum -= array[i];
	int notake = 0;
	int take = 0;
	if(mbinary[i]=='1'){
		notake = allsum;
		take = solve(array, mbinary,n,i+1) + array[i];
	} else {
		take = solve(array, mbinary,n,i+1);
	}
	return max(take, notake);
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	reverse(array.begin(), array.end());
	string mbinary;
	cin>>mbinary;
	reverse(mbinary.begin(), mbinary.end());
	for(int i = 0; i<n; i++){
		allsum += array[i];
		if(mbinary[i]=='1'){
			allonesum+=array[i];
		}
	}
	cout<<solve(array,mbinary,n,0);
	return 0;
}