#include <bits/stdc++.h>
#define ll long long
using namespace std;

int getStudent(int node, vector<vector<ll>>&graph, vector<bool>&vis){
    if(vis[node]){
        return node;
    }
    vis[node] = true;
    return getStudent(graph[node][0], graph, vis);
}

void solve()
{
    ll n;
    cin >> n;

    vector<vector<ll>> graph(n + 1,vector<ll>(1));
    for (ll i = 0; i < n; i++)
    {
        ll val;
        cin >> val;

        graph[i + 1][0] = val;
    }

    vector<int> ans(n);

    for (int i = 1; i <= n; i++){
        vector<bool> vis(n+1,false);
        int v = getStudent(i, graph, vis);
        ans[i - 1] = v;
    }

    for (ll a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    solve();
}