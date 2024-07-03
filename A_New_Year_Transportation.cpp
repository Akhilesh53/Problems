#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool dfs(ll i, ll t, vector<vector<ll>> &v, vector<bool> &vis)
{
    if(i == t) return true;
    if(vis[i]) return false;
    vis[i] = true;
    return dfs(v[i][0],t,v,vis);
}

void solve()
{
    ll n,t; cin>> n>> t;

    vector<vector<ll>> v(n+1,vector<ll>(1));

    for(int i=1; i<n; i++){
        cin>> v[i][0];
        v[i][0] += i;
    }

    vector<bool> vis(n+1,false);
    if(dfs(1,t,v,vis)){
        cout<< "YES" << endl;
        return;
    }
    cout<< "NO" << endl;
}

int main()
{
    solve();
}