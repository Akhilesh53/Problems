#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll a1, b1, c1, d1;
    cin >> a1 >> b1 >> c1 >> d1;

    ll a = min(a1, b1);
    ll b = max(a1, b1);
    ll c = min(c1, d1);
    ll d = max(c1, d1);

    if (a < c && b < c && a < d && b < d)
    {
        cout << "No" << endl;
    }
    else if (c < a && c < b && a > d && b > d)
    {
        cout << "No" << endl;
    }
    else if (c < a && d > b)
    {
        cout << "No" << endl;
    }
    else if (c > a && d < b)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}

int main()
{
    ll tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }
}