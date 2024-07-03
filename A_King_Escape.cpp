#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
Alice and Bob are playing chess on a huge chessboard with dimensions 𝑛×𝑛
. Alice has a single piece left — a queen, located at (𝑎𝑥,𝑎𝑦)
, while Bob has only the king standing at (𝑏𝑥,𝑏𝑦)
. Alice thinks that as her queen is dominating the chessboard, victory is hers.

But Bob has made a devious plan to seize the victory for himself — he needs to march his king to (𝑐𝑥,𝑐𝑦)
 in order to claim the victory for himself. As Alice is distracted by her sense of superiority, she no longer moves any pieces around, and it is only Bob who makes any turns.

Bob will win if he can move his king from (𝑏𝑥,𝑏𝑦)
 to (𝑐𝑥,𝑐𝑦)
 without ever getting in check. Remember that a king can move to any of the 8
 adjacent squares. A king is in check if it is on the same rank (i.e. row), file (i.e. column), or diagonal as the enemy queen.

Find whether Bob can win or not.
*/

vector<vector<int>>dirs{{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

bool killedByQueen(int x, int y, int ax, int ay, int n){

    // if it is the same row or column of queen
    if(x == ax || y == ay){
        return true;
    }

    // if it is in upper left diagonal of queen
    if(x < ax && y < ay){
        if(ax - x == ay - y){
            return true;
        }
    }

    // if it is in upper right diagonal of queen
    if(x < ax && y > ay){
        if(ax - x == y - ay){
            return true;
        }
    }

    // if it is in lower left diagonal of queen
    if(x > ax && y < ay){
        if(x - ax == ay - y){
            return true;
        }
    }

    // if it is in lower right diagonal of queen
    if(x > ax && y > ay){
        if(x - ax == y - ay){
            return true;
        }
    }
    return false;
}

bool safe(int x, int y, int n, int ax, int bx){
    // safe means king should not be killed by queen
    if(x >= 1 && x <= n && y >= 1 && y <= n && !killedByQueen(x,y,ax,bx,n)){
        return true;
    }
    return false;
}

void solve(){
    ll n,ax,ay,bx,by,cx,cy;
    cin>>n>>ax>>ay>>bx>>by>>cx>>cy;

    
    // if king is already at the destination
    if(bx == cx && by == cy){
        cout<<"YES"<<endl;
        return;
    }

   // if cx,cy is in the same row or column of queen, it is not possible to reach there
   if(ax == cx || ay == cy){
       cout<<"NO"<<endl;
       return;
   }

    // if the queen is in the same row or column of the king, it is not possible to reach there
    if(ax == bx && ay == by){
        cout<<"NO"<<endl;
        return;
    }
    // traverse from king start point in all 8 adjacent directions
    queue<pair<int,int>>q;
    q.push({bx,by});

    //visited array
    vector<vector<int>>vis(n+1, vector<int>(n+1, false));
    vis[bx][by] = true;

    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        
       // cout<<curr.first<<" "<<curr.second<<" ============================== "<<endl;

        for(int i=0;i<8;i++){
            int x = curr.first + dirs[i][0];
            int y = curr.second + dirs[i][1];
            // if any of the direction reaches the destination, print YES
                if(x == cx  && y == cy){
                    cout<<"YES"<<endl;
                    return;
                }
            //cout<<x<<" "<<y;
            // if any of the direction is not safe, ignore that direction
            if(safe(x,y,n,ax,ay) && !vis[x][y]){
                vis[x][y] = true;
                q.push({x,y});
                //cout<<" safe"<<endl;
            }
        }
    }
    // else print NO
    cout<<"NO"<<endl;
}

int main()
{
    solve();
}