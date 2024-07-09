#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n; cin>> n;
    vector<ll> a(n);

    for(ll i=0; i<n; i++){
        cin>>a[i];
    }

    if(a[0] == a[n-1]){
        cout<<"NO"<<endl;
    }else{
        string ans = string(n,'R');
        ans[1] = 'B';
        cout<<"YES"<<endl<<ans<<endl;
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