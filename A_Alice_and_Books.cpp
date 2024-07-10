#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    ll maxVal = 0;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];

        if(i != n-1)
        maxVal = max(maxVal, arr[i]);
    }
    cout << maxVal+arr[n-1] << endl;
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