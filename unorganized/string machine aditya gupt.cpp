#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool issubsequence(string &s1, string &s2)
{
    ll n = s1.length(), m = s2.length();
    ll i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    return i == n;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;

    vector<int> p(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> p[i];
        p[i]--;
    }

    ll l = 1, r = m;
    ll ans = -1;

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        string s = "";
        for (ll i = 0; i < m; i++)
        {
            s += '*';
        }
        for (ll i = 0; i < mid; i++)
        {
            s[p[i]] = s2[p[i]];
        }
        if (issubsequence(s1, s))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}