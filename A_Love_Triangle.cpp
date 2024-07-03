#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool detectCycle(vector<vector<ll>> &graph, vector<bool>&vis,ll start, ll node, ll count){
    //cout<<start<<" "<<node<<" "<<count<<endl;
    if(count == 3){
        if(graph[node][0] == start){
            return true;
        }
        return false;
    }

    vis[node] = true;

    if(!vis[graph[node][0]]){
        if(detectCycle(graph, vis, start, graph[node][0], count+1)){
            return true;
        }
    }
    
    return false;
}

void solve(){
    ll n;
    cin >> n;

    vector<vector<ll>> graph(n + 1,vector<ll>(1));

    for (ll i = 1; i <= n; i++){
        ll x;
        cin >> x;
        graph[i][0]=x;
    }

    // detect cycle for only triangle
    // means consider only 3 nodes
    for(int i=1;i <= n;i++){
        vector<bool>vis(n+1, false);
        if(detectCycle(graph,vis, i,i,1)){
            cout<< "YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;

}

int main()
{
    solve();
}