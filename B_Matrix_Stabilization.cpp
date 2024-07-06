#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll r,c; cin>> r>> c;

    vector<vector<ll>> v(r,vector<ll>(c));

    for(int i=0; i < r; i++){
        for(int j=0; j < c;j++){
            cin>>v[i][j];
        }
    }

    for(int i=0; i < r; i++){
        for(int j=0; j < c;j++){
           
           bool left = true,right = true,up = true,down = true;
           ll maxVal = 0;

           if(j-1 >= 0){
               if(v[i][j] <= v[i][j-1]) left = false;
               else maxVal = max(maxVal,v[i][j-1]);
           }

            if(j+1 < c){
                if(v[i][j] <= v[i][j+1]) right = false;
                else maxVal = max(maxVal,v[i][j+1]);
            }

            if(i-1 >= 0){
                if(v[i][j] <= v[i-1][j]) up = false;
                else maxVal = max(maxVal,v[i-1][j]);
            }

            if(i+1 < r){
                if(v[i][j] <= v[i+1][j]) down = false;
                else maxVal = max(maxVal,v[i+1][j]);
            }
            
            //cout<<left<<right<<up<<down<<endl;
            if(left && right && up && down){
               v[i][j] = maxVal;
            }
        }
    }

    for(int i=0; i < r; i++){
        for(int j=0; j < c;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

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