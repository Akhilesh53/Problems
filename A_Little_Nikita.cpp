#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n,m; cin >> n >> m;

    if(n >= m && (n%2 == m%2)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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