#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dfs(ll i, vector<vector<ll>> &graph){
    int h = 0;

    while(i != -1){
        h++;
        i = graph[i][0];
    }
    return h;
}

void solve(){

    ll n;cin>>n;

    vector<vector<ll>> graph(n+1,vector<ll>(1));

    for(int i=1; i<=n; i++){
        ll x; cin>>x;
        graph[i][0] = x;
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans,dfs(i,graph));
    }
    cout<<ans<<endl;
}

int main(){
    solve();
}