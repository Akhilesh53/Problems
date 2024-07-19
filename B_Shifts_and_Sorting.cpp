#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve1()
{
    string s; cin >> s;
    
    if(s.length() <= 1){
        cout<<0<<endl;
        return;
    }
    
    ll ans = 0;
    for(int i=0; i < s.length(); i++){
        if(s[i] == '1'){
            int idx = i+1;
            while(idx < s.length() && s[idx] == '1'){
                idx++;
            }
            if(idx >= s.length()){
                break;
                return;
            }
            ans += idx - i + 1;
            swap(s[i],s[idx]);
        }
    }
    cout<<ans<<endl;
}

void solve()
{
    string s; cin >> s;
    
    if(s.length() <= 1){
        cout<<0<<endl;
        return;
    }
    
    ll numZeroes = 0;
     for(int i=0; i < s.length(); i++){
        if(s[i]=='0'){
            numZeroes++;
        }
     }

    ll ans = 0;
    vector<ll>v(2);
    for(int i=0; i < s.length(); i++){
        v[s[i]-'0']++;

        if(s[i] == '0'){
            if(v[1] > 0){
                ans++;
            }
        }else{
            ans += numZeroes - v[0];
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