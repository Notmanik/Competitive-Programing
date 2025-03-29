#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long t;

    cin >> t;

    while (t--)
    {

        string s;

        cin >> s;

        char zeros = '0';

        char ones = '1';

        long long counter0 = 0, counter1 = 0;

        for (long long i = 0; i < s.length(); i++)
        {

            if (s[i] == zeros)
            {

                counter0++;
            }

            else
            {

                counter1++;
            }
        }

        long long ans, ans2 = 0;

        if (counter0 == counter1)
        {

            ans2 = s.length();
        }

        for (ans = 0; ans < s.length(); ans++)
        {

            if (counter1 > 0 && s[ans] == zeros)
            {

                counter1--;
            }

            else if (counter0 > 0 && s[ans] == ones)
            {

                counter0--;
            }

            else
            {

                break;
            }
        }

        long long operations = s.length() - ans;

        if (ans2 != 0)
        {

            cout << 0 << "\n";
        }

        else
        {

            cout << operations << "\n";
        }
    }

    return 0;
}