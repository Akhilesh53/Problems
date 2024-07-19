#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    for (int i = n; i > m; i--)
    {
        cout << i << " ";
    }
    for (int i = 1; i <= m; i++)
    {
        cout << i << " ";
    }
    cout << endl;
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