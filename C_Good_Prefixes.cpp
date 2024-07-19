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

    ll sum=0;
    ll mx = 0;
    ll ans = 0;

    for(int i=0;i < n;i++){
        sum += vec[i];
        mx = max(mx, vec[i]);

        if(sum-mx == mx){
            ans++;
        }
    }
    cout<<ans<<endl;
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