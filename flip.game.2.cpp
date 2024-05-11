#include <bits/stdc++.h>
using namespace std;

/*
   You are playing the following Flip Game with your friend:
   Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--".
   The game ends when a person can no longer make a move and therefore the other person will be the winner.
   Write a function to determine if the starting player can guarantee a win.

   For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".
*/

bool CanWin(string s, map<string, bool> &dp)
{
    if (dp.find(s) != dp.end())
    {
        return dp[s];
    }
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '+' && s[i - 1] == '+')
        {
            s[i] = s[i - 1] = '-';
            if (!CanWin(s, dp))
            {
                return dp[s] = true;
            }
            s[i] = s[i - 1] = '+';
        }
    }
    return dp[s] = false;
}

int main()
{
    string s = "++++";
    map<string, bool> dp;
    cout << CanWin(s, dp) << endl;
    return 0;
}