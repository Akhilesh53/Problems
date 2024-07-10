#include <bits/stdc++.h>
#define ll long long
using namespace std;

// understand the cyclic depency in the array
// for the last and first element
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll idx = -1;

    for (ll i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            idx = i - 1;
            break;
        }
    }

    // cout<<idx<<" ";
    if (idx == -1)
    {
        cout << "YES" << endl;
        return;
    }

    bool flg = 0;
    for (ll i = idx + 1; i < n; i++)
    {
        if (arr[i] > arr[(i + 1) % n])
        {
            // cout<<i<<" ";
            flg = 1;
            break;
        }
    }

    // cout<<flg<<endl;
    if (!flg)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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