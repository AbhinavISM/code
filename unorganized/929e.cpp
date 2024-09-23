#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

ll summ(vector<ll>& pref,ll i,ll u, ll start){

    return ((pref[i]- pref[start-1])*(2*u - (pref[i] - pref[start-1]-1)))/2;
}

int ternary_search(int l, int r, int u, vector<int> &pref) {
    int givenL = l;
    while (r - l > 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = summ(pref,m1,u,givenL);      //evaluates the function at m1
        int f2 = summ(pref,m2,u,givenL);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    int maxi = summ(pref,l,u,givenL);
    for(int i = l+1; i<=r; i++){
        maxi = max(maxi, summ(pref,i,u,givenL));
    }
    if(maxi==summ(pref,l,u,givenL)){
        return l;
    } else if(maxi==summ(pref,l+1,u,givenL)){
        return l+1;
    } else if(maxi==summ(pref,l+2,u,givenL)){
        return l+2;
    } else {
        return l+3;
    }
}

int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
        ll n;cin>>n;
        vector<ll> v(n);
        for(auto &it : v)cin>>it;
        ll q;cin>>q;
        vector<ll> prefix(n+2,0);
        for(ll i=0;i <n ;++i){
            prefix[i+1] = prefix[i] + v[i];
        }
        while(q--){
            ll l , u;
            cin>>l>>u;
            cout<<ternary_search(l,n,u,prefix)<<" ";
        }
        cout<<'\n';
    }
	return 0;
}