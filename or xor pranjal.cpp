int soln2(vector<int> a,int n, int k){
    int dp1[2][k+1][128],dp2[2][k+1][128];
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));

    dp1[0][0][0]=1;
    dp2[(n+1)%2][0][0]=1;

    vector<vector<int>> b(n+1),c(n+1);
    for(int i=1;i<=n;i++){
        int x=a[i-1];
        dp1[i%2][0][0]=1;
        for(int j=1;j<=k;j++){
            for(int y=0;y<=127;y++){
                dp1[i%2][j][y]=dp1[(i-1)%2][j][y];
            }

            for(int y=0;y<=127;y++){
                if(dp1[(i-1)%2][j-1][y]){
                    dp1[i%2][j][y|x]=1;
                }
            }
        }

        for(int y=0;y<=127;y++){
            if(dp1[i%2][k][y]) b[i].push_back(y);
        }
    }

    for(int i=n;i>=1;i--){
        int x=a[i-1];
        dp2[i%2][0][0]=1;
        for(int j=1;j<=k;j++){
            for(int y=0;y<=127;y++){
                dp2[i%2][j][y]=dp2[(i+1)%2][j][y];
            }

            for(int y=0;y<=127;y++){
                if(dp2[(i+1)%2][j-1][y]){
                    dp2[i%2][j][y|x]=1;
                }
            }
        }

        for(int y=0;y<=127;y++){
            if(dp2[i%2][k][y]) c[i].push_back(y);
        }
    }

    int ans=0;
    for(int i=1;i<n;i++){
        for(auto x:b[i]){
            for(auto y:c[i+1]){
                ans=max(ans,x^y);
            }
        }
    }
    return ans;


}