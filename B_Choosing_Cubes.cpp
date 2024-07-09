#include <bits/stdc++.h>
#define ll long long
using namespace std;

static bool comp(pair<ll,ll> a, pair<ll,ll> b){
    return a.first > b.first;
}

void solve()
{
    ll n, f, k;
    cin>>n>>f>>k;

    vector<pair<ll,ll>> v(n);

    for(ll i=0; i<n; i++){
        ll val; cin>>val;
        v[i] = {val, i};
    }

    pair<ll,ll> val = v[f-1];

    sort(v.begin(), v.end(),comp);
    
    ll beforeK = 0;
    for(int i=0;i<k;i++){
        if(v[i].first == val.first){
            beforeK++;
        }
    }
    ll afterK = 0;
    for(int i=k;i<n;i++){
        if(v[i].first == val.first){
            afterK++;
        }
    }
    
    if(beforeK > 0 && afterK > 0){
        cout<<"Maybe"<<endl;
        return;
    }
    
    if(beforeK > 0){
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
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