#include <bits/stdc++.h>
using namespace std;

// dfs wil return the minnimum number of transactions required to settle the balances
int dfs(int n, vector<int> &balances, int start)
{
     if(n == 0 || start >= n)
        return 0;

    // if tehre is any 0 balance, we can skip that
    while (start < n && balances[start] == 0)
        start++;

    int ans = INT_MAX;
    for (int i = start + 1; i < n; i++){
        // negative balance should completely cutoff means negative balance should be made to 0
        // if we can settle balance
        if (balances[start] * balances[i] < 0){
            balances[i] += balances[start];
            ans = min(ans, 1 + dfs(n,balances, start + 1));
            balances[i] -= balances[start];

            // if it completely negotiates, no need to go further
            if(balances[start] * balances[i] == 0){
                break;
            }
        }
    }
    return ans;
}
int main()
{

    // vcreate a vector of balances
    // sum of all values of balnces should be zero
    vector<int> balances = {200, -100, 50, -50, -80, -20};
    int n = balances.size();
    return dfs(n, balances, 0);
}

