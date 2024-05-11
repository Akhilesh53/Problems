/*
     In this problem, we're given a graph that is composed of 'n' nodes which are labeled from 0 to n - 1.
     The graph also has a set of edges given in a list where each edge is represented by a pair of nodes
     like [a, b] that signifies a bidirectional (undirected) connection between node a and node b.
     Our main objective is to determine if the given graph constitutes a valid tree.
     To understand what makes a valid tree, we should recall two essential properties of trees:
       - A tree must be connected, which means there should be some path between every pair of nodes.
       - A tree cannot have any cycles, meaning no path should loop back on itself within the graph.
     Therefore, our task is to check for these properties in the given graph. We need to verify if there's exactly one path between any two nodes (confirming a lack of cycles) and that all the nodes are reachable from one another (confirming connectivity). If both conditions are met, we return true; otherwise, we return false.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

// Find the parent of a node
int find(int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = find(parent[node]);
}

// Union of two subsets
void unionSet(int node1, int node2)
{
    parent[find(node1)] = find(node2);
}

// initialise parent
void init(int n)
{
    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }
}

// Check if a graph is a tree or not
bool isTree(int nodes, vector<pair<int, int>> &edges)
{

    init(nodes);

    int components = nodes;
    for (auto &edge : edges)
    {
        int node1 = edge.first, node2 = edge.second;
        if (find(node1) == find(node2))
        {
            return false; // Cycle detected
        }
        unionSet(node1, node2);
        components--;
    }
    return components == 1; // Only one connected component
}

int main()
{
    int nodes = 5;
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    if (isTree(nodes, edges))
    {
        cout << "The graph is a tree.\n";
    }
    else
    {
        cout << "The graph is not a tree.\n";
    }
    return 0;
}