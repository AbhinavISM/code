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
	int n;
	cin>>n;
	int k;
	cin>>k;
	vector<int> fruits(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		fruits[i] = item;
	}
	vector<int> heights(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		heights[i] = item;
	}
	int maxsublen = 1;
	int cursublen = 1;
	int fruitCount = fruits[n-1];
	int lastheight = heights[n-1];
	if(fruitCount>k){
		maxsublen = 0;
		cursublen = 0;
		fruitCount = 0;
		lastheight = 1;
	}
	for(int i = n-2; i>=0; i--){
		if(heights[i]%lastheight==0){
			if(fruitCount+fruits[i]<=k){
				cursublen++;
				fruitCount += fruits[i];
			} else {
				// int temp = cursublen;
				fruitCount += fruits[i];
				cursublen++;
				while(fruitCount>k&&cursublen>1){
					fruitCount-=fruits[i+cursublen-1];
					cursublen--;
				}
			}
		} else {
			cursublen = 1;
			fruitCount = fruits[i];
		}
		lastheight = heights[i];
		if(fruitCount>k){
			cursublen = 0;
			fruitCount = 0;
			lastheight = 1;
		}
		maxsublen = max(maxsublen,cursublen);
	}
	cout<<maxsublen<<"\n";
}
	return 0;
}