#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n; cin >> n;

    vector<ll> ans(n);

    ll s = 550;
    ans[0] = s;
    for(ll i = 1; i < n; i++){
       ll v; cin >> v;

       ans[i] = s += v;
    }

    for(int v : ans){
        cout<<v<<" ";
    }
    cout<<endl;
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