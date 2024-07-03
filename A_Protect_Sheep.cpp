#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll r,c; cin>> r >> c;

    vector<vector<char>> v(r, vector<char>(c));

    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            cin>> v[i][j];
        }
    }

    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            if(v[i][j] == 'S'){
                if(i>0 && v[i-1][j] == 'W'){
                    cout<< "NO\n";
                    return;
                }else if(i>0 && v[i-1][j] == '.'){
                    v[i-1][j] = 'D';
                }

                if(i<r-1 && v[i+1][j] == 'W'){
                    cout<< "NO\n";
                    return;
                }else if(i<r-1 && v[i+1][j] == '.'){
                    v[i+1][j] = 'D';
                }

                if(j>0 && v[i][j-1] == 'W'){
                    cout<< "NO\n";
                    return;
                }else if(j>0 && v[i][j-1] == '.'){
                    v[i][j-1] = 'D';
                }

                if(j<c-1 && v[i][j+1] == 'W'){
                    cout<< "NO\n";
                    return;
                }else if(j<c-1 && v[i][j+1] == '.'){
                    v[i][j+1] = 'D';
                }
            }
        }
    }

    std::cout<< "YES"<<std::endl;
    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            std::cout<< v[i][j];
        }
        std::cout<< std::endl;
    }

}

int main()
{
    solve();
}