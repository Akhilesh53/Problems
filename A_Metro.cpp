#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool dfs(int node, int target,vector<vector<int>>&graph,vector<int>&visited){
    //cout<<node<<" "<<target<<endl;
    if(node == target){
        return true;
    }
    
    visited[node] = 1;

    for(int i=0;i<graph[node].size();i++){
        if(visited[graph[node][i]] == 0){
            if(dfs(graph[node][i],target,graph,visited)){
                return true;
            }
        }
    }
    return false;
}

vector<vector<int>> makeGraph(int n,int s,vector<int> forward,vector<int> backward){
    vector<vector<int>>graph(n+1);

    int prev = 0;

    for(int i=1; i < n;i++){
        if(forward[i] == 1){
            graph[prev+1].push_back(i+1);
            prev = i;
        }
    }

    vector<int>vis(n+1,false);

    prev = n-1;

    while(prev >= 0 && backward[prev] == 0){
        prev--;
    }

    for(int i=prev-1;i>=0;i--){
        if(backward[i] == 1){
            graph[prev+1].push_back(i+1);
            prev = i;
        }
    }
    return graph;
}

void solve(){
    ll n,s;
    cin>>n>>s;

    vector<int> forward(n);
    vector<int> backward(n);

    for(int i=0;i<n;i++){
        cin>>forward[i];
    }

    if (forward[0]==0){
        cout<<"NO"<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        cin>>backward[i];
    }

   vector<vector<int>> graph =  makeGraph(n,s,forward,backward);

   
   vector<int>vis(n+1,false);

   if(dfs(1,s,graph,vis)){
       cout<<"YES"<<endl;
       return;
   }
   cout<<"NO"<<endl;
}

int main(){
    solve();
}