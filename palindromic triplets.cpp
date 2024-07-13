#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
	ll n;
	cin>>n;
	string s;
	cin>>s;
	vector<vector<ll>> ispal(n,vector<ll>(n));
   for(ll i = 0;i<n;i++){
	ispal[i][i] = 1;
   }
   for(ll i = n-1;i>=0;i--){
	for(ll j = i+1;j<n;j++){
		if(j-i==1){
			if(s[i]==s[j]){
				ispal[i][j] = 1;
			}
		}else{
			if(ispal[i+1][j-1]==1 && s[i]==s[j]){
				ispal[i][j] = 1;
			}
		}
	}
   }
   vector<vector<ll>> numpal(n,vector<ll>(n));
   for(ll i = 0;i<n;i++){
	numpal[i][i] = 1;
	  for(ll j = i-1;j>=0;j--){
		numpal[j][i] = numpal[j+1][i];
              if(ispal[j][i]==1){
				numpal[j][i]+=1;
			  }
	  }
	}
   vector<ll> pass(n);
   for (ll i = 0; i < n; i++)
   {
       ll count = 0;
         for(ll j = i;j<n;j++){
              count+= numpal[i][j];
         }
         pass[i] = count;
   }
    
   ll ans = 0;
   for(ll i = 0;i<n-2;i++){
	for(ll j = i+1;j<n-1;j++){
          ll x = numpal[0][i];
		  ll y = numpal[i+1][j];
		  ll z = pass[j+1];
           ans+= x*y*z;
	}
   }
   cout<<ans<<endl;
}
int main() {
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}