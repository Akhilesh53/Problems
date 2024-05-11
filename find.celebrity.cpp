#include <iostream>
#include <vector>

using namespace std;

// Function to find the celebrity 
int findCelebrity(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    // Create a vector to store the indegree and outdegree of each node
    vector<int> indegree(n, 0), outdegree(n, 0);

    // Calculate the indegree and outdegree of each node
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j]) {
                outdegree[i]++;
                indegree[j]++;
            }
        }
    }

    // Find the celebrity
    for(int i = 0; i < n; i++) {
        if(indegree[i] == n - 1 && outdegree[i] == 0) {
            return i;
        }
    }
    return -1;
}


int main() {
    // Read the number of nodes and edges
    int n, m;
    cin >> n >> m;

   // create a matrix of m*n which have binary values in  it
   vector<vector<int>> matrix(n, vector<int>(m, 0));

   // take input for the matrix
    for(int i = 0; i < n; i++) {
         for(int j = 0; j < m; j++) {
              cin>>matrix[i][j];
         }
    }

    // Find the celebrity
    int celebrity = findCelebrity(matrix);
    cout << celebrity << endl;
}