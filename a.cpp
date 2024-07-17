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

int rec(int ind, int k, string &s, vector<ll> &p, vector<vector<ll>> &dp)
{
    if (k == 0)
        return 0;
    if (ind < 0)
        return 0;
    if (dp[ind][k] != -1)
        return dp[ind][k];
    if (k == 1)
    {
        auto ways = rec(ind - 1, k, s, p, dp);
        for (int i = 0; i <= ind; i++)
        {
            if (isPalindrome(i, ind, p))
            {
                ways++;
            }
        }
        return dp[ind][k] = ways;
    }
    auto ways = rec(ind - 1, k, s, p, dp);
    for (int i = 0; i <= ind; i++)
    {
        if (isPalindrome(i, ind, p))
        {
            ways += rec(i - 1, k - 1, s, p, dp);
        }
    }
    return dp[ind][k] = ways;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> p = manacher(s);

    vector<vector<ll>> dp(n, vector<ll>(4, -1));

    auto tmp = rec(n - 1, 3, s, p, dp);

    cout << tmp << '\n';
    return 0;
}