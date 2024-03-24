#include<bits/stdc++.h>
#define int long long
using namespace std;
//     int prd(vector<int> &a, int k, double x)
// {
//     if (x == 0) return true;
//     int cnt = 0;
//     for (int i = 0; i < a.size(); ++i)
//         cnt += a[i] / x;
//     return cnt >= k;
// }
int query (int l, int r){
    int result;
    cout<<"? "<<l<<" "<<r<<"\n";
    cin>>result;
    return result;
}
int32_t main()
{

    int n;
    cin>>n;
    int lo = 1;
    int hi = n;
    while(hi>=lo){
        if(hi==lo){
            cout<<"! "<<hi;
        }
        int mid = lo + (hi-lo)/2;
        int a = query(lo,hi);
        int b;
        if(a>=mid){
            b = query(mid, hi);
            if(b==a){
                lo = mid;
            } else {
                hi = mid;
            }
        } else {
            b = query(lo,mid-1);
            if(b==a){
                hi  = mid-1;
            } else {
                lo = mid;
            }
        }
    }


// PACKING RECTANGLES


    // int w,h,n;
    // cin>>w>>h>>n;
    // int hi = 1000000000;
    // int lo = 0;
    // int ans = 0;
    // // int area = n*w*h;
    // while(hi>=lo){
    //     int mid = lo + (hi-lo)/2;
    //     if((mid/w)*(mid/h) >= n){
    //         ans = mid;
    //         hi = mid - 1;
    //     } else {
    //         lo = mid + 1;
    //     }
    // }
    // cout<<ans;


// R O P E S
    // cout<<setprecision(7);
    // int n;
    // int k;
    // cin>>n;
    // cin>>k;
    // std::vector<int> ropeLengths;
    // for (int i = 0; i < n; ++i)
    // {
    //     int item;
    //     cin>>item;
    //     ropeLengths.push_back(item);
    // }
    // double hi = 10000000;
    // double lo = 0;
    // double ans;
    // int l = 100;
    // while(hi-lo>0.000001){
    //     double mid = lo + (hi-lo)/2;
    //     if(mid == 0){
    //         ans = mid;
    //         lo = mid;
    //         continue;
    //     }
    //     int pieces = 0;
    //     for(int len : ropeLengths){
    //         pieces += (int) ((double)len)/(double)mid;
    //     }
    //     if(pieces>=k){
    //         ans = mid;
    //         lo = mid;
    //     } else {
    //         hi = mid;
    //     }
    // }
    // cout<<ans;


    // cout<<setprecision(7);
    // int n, k;
    // cin >> n >> k;
    // vector<int>a(n);
    // for (auto &i : a) cin >> i;

    // double l = 0, r = 1e8, mid;
    // int lp = 100;
    // while (lp--)
    // {
    //     mid = l + (r - l) / 2;
    //     if (prd(a, k, mid))
    //         l = mid;
    //     else
    //         r = mid;
    // }
    // cout << l;
}
