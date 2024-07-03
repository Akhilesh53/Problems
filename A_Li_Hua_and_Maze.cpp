#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n,m,sr,sc,er,ec;
    cin >> n >> m >> sr >> sc >> er >> ec;

    sr--;
    sc--;
    er--;
    ec--;

    if(sr == er && sc == ec){
        cout<<0<<endl;
        return;
    }

    if(sr == 0 && (sc == 0 || sc == m-1)){
        cout<<2<<endl;
        return;
    }

    if(sr==n-1 && (sc == 0 || sc == m-1)){
        cout<<2<<endl;
        return;
    }

    if(er==n-1 && (ec == 0 || ec == m-1)){
        cout<<2<<endl;
        return;
    }

     if(er == 0 && (ec == 0 || ec == m-1)){
        cout<<2<<endl;
        return;
    }

    if(sr == 0 || sr == n-1){
        cout<<3<<endl;
        return;
    }

    if(sc == 0 || sc == m-1){
        cout<<3<<endl;
        return;
    }

    if(er == 0 || er == n-1){
        cout<<3<<endl;
        return;
    }

    if(ec == 0 || ec == m-1){
        cout<<3<<endl;
        return;
    }

    cout<<4<<endl;
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