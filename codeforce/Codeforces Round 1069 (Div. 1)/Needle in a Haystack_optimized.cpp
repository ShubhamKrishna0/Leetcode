#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        string s, t;
        cin >> s >> t;

        vector<int> cntT(26, 0), need(26, 0);

        // Count characters in t
        for (char c : t)
            cntT[c - 'a']++;

        // Count required characters from s
        for (char c : s)
            need[c - 'a']++;

        // Basic feasibility check
        for (int i = 0; i < 26; i++)
        {
            if (need[i] > cntT[i])
            {
                cout << "Impossible\n";
                goto next_case;
            }
        }

        {
            string ans;
            int ptr = 0; // pointer in s

            for (int pos = 0; pos < (int)t.size(); pos++)
            {

                for (int c = 0; c < 26; c++)
                {
                    if (cntT[c] == 0)
                        continue;

                    // Try using character c
                    cntT[c]--;

                    bool advance = false;
                    if (ptr < (int)s.size() && c == s[ptr] - 'a')
                    {
                        need[c]--;
                        ptr++;
                        advance = true;
                    }

                    // Check feasibility
                    bool ok = true;
                    for (int i = 0; i < 26; i++)
                    {
                        if (need[i] > cntT[i])
                        {
                            ok = false;
                            break;
                        }
                    }

                    if (ok)
                    {
                        ans.push_back(char('a' + c));
                        break;
                    }

                    // rollback
                    cntT[c]++;
                    if (advance)
                    {
                        ptr--;
                        need[c]++;
                    }
                }
            }

            cout << ans << "\n";
        }

    next_case:;
    }

    return 0;
}