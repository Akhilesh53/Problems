#include<bits/stdc++.h>
using namespace std;

void findConnectedComponents(vector<vector<int>> &graph, int node, vector<bool> &visited) {
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int currNode = graph[node][i];
        if (!visited[currNode]) {
            findConnectedComponents(graph,currNode, visited);
        }
    }
}

int numberOfConectedComponents(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            findConnectedComponents(graph, i, visited);
        }
    }
    return components;
}