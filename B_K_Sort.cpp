#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n; cin>>n;

    vector<ll> vec(n);

    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    ll ans = 0;
    ll mx = 0;
    ll prevMax = 0;

    for(int i=0; i<n; i++){
       prevMax = max(prevMax, vec[i]);

       ll d = prevMax - vec[i];

       ans += d;
       mx = max(mx, d);
    }
    cout<<mx+ans<<endl;
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