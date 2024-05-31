#include<bits/stdc++.h>
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int NthRoot(int n, int m) {
  // Write your code here.
  int hi = m;
  int lo = 1;
  while(hi>=lo){
    long long mid = lo + (hi-lo)/2;
    long long res = 1;
    for(int i = 1; i<=n; i++){
      res = res*mid;
      if(res>m) break;
    }
    if(res==m) return mid;
    else if(res>m) hi = mid - 1;
    else lo = mid + 1;
  }
  return -1;
}

int32_t main(){
	cout<<NthRoot(9, 1953125);
}