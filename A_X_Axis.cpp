#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll x1,x2,x3;
    cin>>x1>>x2>>x3;

    ll minVal = INT_MAX;

    if(abs(x1-x2) + abs(x1-x3) < minVal){
       minVal = abs(x1-x2) + abs(x1-x3);
    }

    if(abs(x2-x1) + abs(x2-x3) < minVal){
       minVal = abs(x2-x1) + abs(x2-x3);
    }

    if(abs(x3-x1) + abs(x3-x2) < minVal){
       minVal = abs(x3-x1) + abs(x3-x2);
    }
    cout<<minVal<<endl;
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