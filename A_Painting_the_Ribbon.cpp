#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll parts, colors, maxRepaintParts; 
    cin >> parts >> colors >> maxRepaintParts;

    if(colors == 1 || parts == 1){
        cout<<"No"<<endl;
        return;
    }

    ll maxColours = parts/colors; // max times a color can occur

    if(parts%colors != 0){
       maxColours++;
    }

    ll partsLeftForRepaint = parts - maxColours; // colors left after maxColours

    if(partsLeftForRepaint <= maxRepaintParts){ // bob can paint all parts with same color, 
        cout<<"No"<<endl;                       // we cannot paint with different colors so print No
        return;
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