#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, c, d;
    cin >> n >> c >> d;

    map<int, int> freq;
    ll minVal = INT_MAX;

    for (int i = 0; i < n * n; i++)
    {
        ll val;
        cin >> val;
        minVal = min(minVal, val);
        freq[val]++;
    }

    vector<vector<ll>> vec(n, vector<ll>(n, -1));

    vec[0][0] = minVal;
    freq[minVal]--;

    for(int i=0; i < n-1;i++){
        for(int j=0; j < n-1; j++){

            // check i+1, j
            if(vec[i+1][j] == -1){
                if (freq[vec[i][j] + c] > 0){
                    vec[i+1][j] = vec[i][j] + c;
                    freq[vec[i][j] + c]--;
                }else{
                    cout<<"No"<<endl;
                    return;
                }
            }else{
                if(vec[i][j] + c != vec[i+1][j]){
                   cout<<"No"<<endl;
                    return;
                }
            }

            // check i, j+1
            if(vec[i][j+1] == -1){
                if(freq[vec[i][j] + d] > 0){
                    vec[i][j+1] = vec[i][j] + d;
                    freq[vec[i][j] + d]--;
                }else{
                    cout<<"No"<<endl;
                    return;
                }
            }else{
                if(vec[i][j] + d != vec[i][j+1]){
                    cout<<"No"<<endl;
                    return;
                }
            }
            
        }
    }

    // traverse for the last row
    ll lastRow = n-1;
    for(int i=0; i < n-1; i++){
        if(vec[lastRow][i+1] == -1){
            if(freq[vec[lastRow][i] + d] > 0){
                vec[lastRow][i+1] = vec[lastRow][i] + d;
                freq[vec[lastRow][i] + d]--;
            }else{
                cout<<"No"<<endl;
                return;
            }
        }else{
            if(vec[lastRow][i] + d != vec[lastRow][i+1]){
                cout<<"No"<<endl;
                return;
            }
        }
    }

    // traverse for the last column
    ll lastCol = n-1;
    for(int i=0; i < n-1; i++){
        if(vec[i+1][lastCol] == -1){
            if(freq[vec[i][lastCol] + c] > 0){
                vec[i+1][lastCol] = vec[i][lastCol] + c;
                freq[vec[i][lastCol] + c]--;
            }else{
                cout<<"No"<<endl;
                return;
            }
        }else{
            if(vec[i][lastCol] + c != vec[i+1][lastCol]){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
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