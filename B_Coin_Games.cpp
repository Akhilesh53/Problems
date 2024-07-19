#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n; cin >> n;

    string s; cin >> s;

    ll cnt = 0;
    for(char c : s){
        if(c == 'U'){
            cnt++;
        }
    }

    if(cnt & 1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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