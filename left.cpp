    //  SEGMENTS WITH SMALL SET
    // int n;
    // cin>>n;
    // int k;
    // cin>>k;
    // vector<int> v;
    // for(int i = 0; i<n; i++){
    //     int item;
    //     cin>>item;
    //     v.push_back(item);
    // }
    // map<int,int> s;
    // s.insert({v[0],1});
    // int l = 0;
    // int r = 0;
    // int uniqueCount = 1;
    // int ans = 0;
    // while(r<n){
    //         /*cout<<"\n"<<"\n";
    //         for(pair<int,int> item : s){
    //             cout<<item.first<<"&"<<item.second<<" ";
    //         }
    //         cout<<"\n"<<"\n";*/
    //     if(uniqueCount<=k){
    //         ans+=r-l+1;
    //         r++;
    //         if(s.find(v[r]) == s.end()){
    //             uniqueCount++;
    //             s.insert({v[r],1});
    //         } else {
    //             s[v[r]] += 1;
    //         }
    //     } else {
    //         l++;
    //         //cout<<"before : "<<s[v[l-1]];
    //         s[v[l-1]] -= 1;
    //         //cout<<"after : "<<s[v[l-1]];
    //         if(s[v[l-1]]==0){
    //             uniqueCount--;
    //         }
    //     }
    // }
    // cout<<ans;

//CHILDREN PARTY
    // int ballons;
    // int assistants;
    // cin>>ballons>>assistants;
    // std::vector<int> work(assistants);
    // std::vector<int> limit(assistants);
    // std::vector<int> rest(assistants);
    // std::vector<int> filled(assistants);
    // for (int i = 0; i < assistants; ++i)
    // {
    //     cin>>work[i]>>limit[i]>>rest[i];
    // }

    // int hi = 1e7;
    // int lo = 0;
    // int ans = 0;
    // while(hi>=lo){
    //     int mid = lo + (hi-lo)/2;
    //     int filledBallons = 0;
    //     for (int i = 0; i < assistants; ++i)
    //     {
    //         int filledThisTime = 0;
    //         int timeLeft = mid;
    //         int limitLeft = limit[i];
    //         while(timeLeft>0){
    //             if(limitLeft==0){
    //                 timeLeft -= rest[i];
    //                 limitLeft = limit[i];
    //                 continue;
    //             }
    //             timeLeft -= work[i];
    //             filledBallons++;
    //             filledThisTime++;
    //             limitLeft--;
    //         }
    //         filled.push_back(filledThisTime);
    //     }
    //     if(filledBallons>=ballons){
    //         ans = mid;
    //         hi = mid-1;
    //     } else {
    //         lo = mid+1;
    //     }
    // }
    // cout<<ans<<"\n";
    // for (int i = 0; i < assistants; ++i)
    // {
    //     cout<<filled[i]<<" ";
    // }


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
