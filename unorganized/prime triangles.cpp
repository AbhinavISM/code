#include<bits/stdc++.h>
// #define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;

vector<bool> isprime(100000001,1);
void calprimes(){
isprime[0] = 0;
isprime[1] = 0;
for(int i = 2; i*i<=100000000; i++){
    if(isprime[i]==1){
        for(int j = i*i; j<=100000000; j+=i){
            isprime[j] = 0;
        }
    }
}
}
int32_t main(){
    fast_io;
    calprimes();
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    if(!isprime[n]){
        cout<<-1<<"\n";
    } else {
        cout<<((int)sqrt(1+8*n)-1)/2<<"\n";
    }

}
    return 0;
}