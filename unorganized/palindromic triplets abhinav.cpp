#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> manacher(string &s)
{
    vector<ll> p;

    string t = "";

    for (auto it : s)
    {
        t += string("#") + it;
    }

    t += string("#");
    ll n = t.size();
    p.resize(n, 1);

    ll l = 1, r = 1;

    for (int i = 1; i < n; i++)
    {
        p[i] = max(0ll, min(r - i, p[l + (r - i)]));

        while (i - p[i] >= 0 && i + p[i] < n && (t[i - p[i]] == t[i + p[i]]))
        {
            p[i]++;
        }

        if (i + p[i] > r)
        {
            l = i - p[i];
            r = i + p[i];
        }
    }

    return p;
}

bool isPalindrome(ll l, ll r, vector<ll> &p)
{
    ll cen = (l + r) / 2, odd = l % 2 == r % 2;
    ll longestSz = p[2 * cen + 1 + !odd] - 1;
    return longestSz >= (r - l + 1);
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> p = manacher(s);
    vector<vector<ll>> dp(n, vector<ll>(4, 0));
    
    for(ll i = 0; i<n; i++){
        for(ll k = 1; k<4; k++){
            if(i>0) dp[i][k] = dp[i-1][k];
            for (ll j = 0; j<=i; j++){
                if(k==1&&isPalindrome(j, i, p)) dp[i][k]++;
                else if(j>0&&isPalindrome(j, i, p)) dp[i][k] += dp[j-1][k-1];
            }
        }  
    }
    cout<<dp[n-1][3];
    return 0;
}