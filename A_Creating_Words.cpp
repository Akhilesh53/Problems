#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    string a,b;
    cin>>a>>b;

    int temp = b[0];
    b[0] = a[0];
    a[0] = temp;

    cout<<a<<" "<<b<<endl;
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