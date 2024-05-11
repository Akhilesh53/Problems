#include <bits/stdc++.h>
using namespace std;

// Problem : https://algo.monster/liteproblems/351

int dfs(int val, int cnt, int m, int n, vector<bool> &visited, vector<vector<int>> &crossEdges){
    // if more than values considered, no need to traverse furtehr
    if(cnt > n) return 0;

    visited[val] = true;

    // whther to consder the current val in the answer or not
    int ans = (cnt >= m) ? 1 : 0;

    // for all the possible values
    for(int i=1;i<=9;i++){
        // if the value is not visited and the cross edge is not visited
        if(!visited[i] && (crossEdges[val][i] == 0 || visited[crossEdges[val][i]])){
            ans += dfs(i, cnt+1, m, n, visited, crossEdges);
        }
    }
    // mark it false for next traversal
    visited[val] = false;
    return ans;

}

// m = min number of values
// n = max number of values
int numberOfPatterns(int m, int n)
{
    vector<vector<int>> crossEdges(10, vector<int>(10, 0));
    crossEdges[1][3] = crossEdges[3][1] = 2;
    crossEdges[1][7] = crossEdges[7][1] = 4;
    crossEdges[3][9] = crossEdges[9][3] = 6;
    crossEdges[7][9] = crossEdges[9][7] = 8;
    crossEdges[1][9] = crossEdges[9][1] = crossEdges[3][7] = crossEdges[7][3] = 5;
    crossEdges[2][8] = crossEdges[8][2] = crossEdges[4][6] = crossEdges[6][4] = 5;

    vector<bool> vis(10, false);

    return dfs(1, 1, m, n, vis, crossEdges) * 4 + dfs(2, 1, m, n, vis, crossEdges) * 4 + dfs(5, 1, m, n, vis, crossEdges);
}