const ll N=1e5;
ll seg[4*N+1],seg1[4*N+1],seg2[4*N+1];
vector<ll> b(N+1);

void build(ll v,ll tl, ll tr){
    if(tl==tr){
        seg[v]= b[tl];
        seg1[v]=b[tl]*tl;
        seg2[v]=b[tl]*tl*tl;
        return;
    }
    ll tm = (tl + tr) / 2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    seg[v] = seg[v*2] + seg[v*2+1];
    seg1[v] = seg1[v*2] + seg1[v*2+1];
    seg2[v] = seg2[v*2] + seg2[v*2+1];
}

void update(ll v, ll tl, ll tr, ll pos, ll val) {
    if (tl == tr) {
        seg[v] = val;
        seg1[v] = tl*val;
        seg2[v] = tl*val*val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, val);
        else
            update(v*2+1, tm+1, tr, pos, val);
        seg[v] = seg[v*2] + seg[v*2+1];
        seg1[v] = seg1[v*2] + seg1[v*2+1];
        seg2[v] = seg2[v*2] + seg2[v*2+1];
    }
}

ll ques(ll v,ll tl,ll tr,ll l,ll r,ll start,ll end){
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return -seg2[v]+(start+end)seg1[v]-(end+1)(start-1)*seg[v];
    }
    ll tm = (tl + tr) / 2;
    return ques(v*2, tl, tm, l, min(r, tm),start,end)
           + ques(v*2+1, tm+1, tr, max(l, tm+1), r,start,end);
}

vector<ll> soln3(vector<ll> a,vector<vector<ll>> query){
    ll n=a.size();
    for(int i=1;i<=n;i++) b[i]=a[i-1];
    for(int i=0;i<=4*n;i++) {
        seg[i]=0;
        seg1[i]=0;
        seg2[i]=0;
    }
    build(1,1,n);
    vector<ll> ans;
    for(auto v:query){
        if(v[0]==1){
            update(1,1,n,v[1],v[2]);
        }else{
            ans.push_back(ques(1,1,n,v[1],v[2],v[1],v[2]));
        }
    }
    return ans;
}