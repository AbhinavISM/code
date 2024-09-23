int n;
        cin >> n;
        vector<int> a(32, 0);
        cout << 32 << '\n';
        for (int i = 0; i < 32; i++)
        {
            if (n & (1ll << i))
            {
                a[i] = 1;
            }
        }
        int prev = -1;
        int cnt = 0;
        for (int i = 0; i < 32; i++)
        {
            if (a[i] == 1)
            {
                if (prev == -1)
                {
                    prev = i;
                }
                else
                {
                    a[i] = 0;
                }
                cnt++;
            }
            else
            {
                if (cnt >= 2 && (i - prev == cnt))
                {
                    a[prev] = -1;
                    a[i] = 1;
                    prev = i;
                    cnt = 1;
                }
                else
                {
                    cnt = 0;
                    prev = -1;
                }
            }
        }
        for (auto it : a)
            cout << it << ' ';
        cout << endl;