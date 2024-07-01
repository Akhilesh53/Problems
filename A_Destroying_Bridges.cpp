#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;

    if (k == 0 || k < n - 1)
        cout << n << endl;
    else if (k >= n - 1)
        cout << 1 << endl;
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