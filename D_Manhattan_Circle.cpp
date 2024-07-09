#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n,m; cin>>n>>m;

    vector<vector<char>>vec(n,vector<char>(m));

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }

    pair<ll,ll> top = {n,m}, bottom = {-1,-1};
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(vec[i][j] == '#'){
                top = min(top,{i,j});
                bottom = max(bottom,{i,j});
            }
        }
    }

    ll x = (top.first + bottom.first)/2 + 1;
    ll y = top.second + 1;
    cout<<x<<" "<<y<<endl;
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