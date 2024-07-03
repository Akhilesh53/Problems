#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n;cin>>n;
    string s,t;cin>>s>>t;

    ll ans = 0;
    vector<bool> vis(n,false);

    for(ll i=0;i<n;i++){
        if(t[i] == '1'){
             if(s[i]=='0'){
                ans++;
            }else if(i-1 >= 0 && s[i-1] == '1' && !vis[i-1]){
                vis[i-1] = true;
                ans++;
            }else if(i+1 < n && s[i+1] == '1' && !vis[i+1]){
                vis[i+1] = true;
                ans++;
            }
        }
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