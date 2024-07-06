#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    string a,b; cin>>a>>b;
    ll ans = a.size() +  b.size();

   for(int str = 0; str < b.size(); str++){
    ll ptr = str;
    for(int i = 0; i < a.size(); i++){
        if(ptr < b.size() && a[i] == b[ptr]){
            ptr++;
        }
    }
    ans = min(ans,(ll)(a.size() + b.size() - (ptr-str)));
   }

    cout<<ans<<endl;
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