#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n,q;
        vector<int> v(n);
        vector<int> presum(n);
        presum[0] = 0;
        vector<int> prexor(n);
        prexor[0] = 0;
        for(int i=0; i<n; i++){
            int item;
            cin>>item;
            v[i]=item;
            if(i==0){
                presum[i] = item;
                prexor[i] = item;
            }
            presum[i] = presum[i-1] + item;
            prexor[i] = prexor[i-1]^item;
        }
        int L,R;
        cin>>L>>R;
        int flr = presum[n-1] - prexor[n-1];
        int rptr = 0;
        int lptr = 0;
        int length = n;
        int rans = n-1;
        int lans = 0;
        while(rptr<n){
            int temp;
            if(lptr!=0){
                temp = (presum[rptr]-presum[lptr-1])-(prexor[rptr]-prexor[lptr-1]);
            } else {
                temp = presum[rptr]-prexor[rptr];
            }
            if(temp==flr){
                rans = rptr;
                lans = lptr;
                length = rptr-lptr+1;
                lptr++;
            } else {
                rptr++;
            }
        }
        cout<<lans+1<<" "<<rans+1;
    }
}
