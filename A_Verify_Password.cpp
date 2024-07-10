#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n;cin>>n;

    string s; cin>>s;

    char prevLetter = '.';
    char prevDigit = '.';
    bool isChar = false;

    for(char c : s){
        if(isdigit(c)){
            if(isChar || (prevDigit != '.' && prevDigit > c)){
                cout<<"NO"<<endl;
                return;
            }
            prevDigit = c;
        }else{
            isChar = true;
            if(prevLetter != '.' && prevLetter > c){
                cout<<"NO"<<endl;
                return;
            }
            prevLetter = c;
        }
    }
    cout<<"YES"<<endl;
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