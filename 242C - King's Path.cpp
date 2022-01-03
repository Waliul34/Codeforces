#include <bits/stdc++.h>
using namespace std;
 
#define piii pair<pair<int, int>, int>
#define lli long long int
#define pir pair<int, int>
 
vector<pir> vec;
map<int, vector<pir> >adj;
map<pir, bool> vis;
int final_i, final_j, start_i, start_j, finl;
int lm = 1000000001;
 
int fx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int fy[] = {0, -1, -1, -1, 0, 1, 1, 1};
 
void bfs()
{
    vis.clear();
    piii frnt;
    pir val;
    int cntt, x, y, i, j, k, m, n, p;
    queue<piii> Q;
    Q.push({{start_i, start_j}, 0});
    vis[{start_i, start_j}] = true;
    while(!Q.empty())
    {
        frnt = Q.front();
        i = frnt.first.first;
        j = frnt.first.second;
        cntt = frnt.second;
        Q.pop();
        if(i == final_i && j == final_j)
        {
            finl = cntt;
            return;
        }
        for(int k = 0; k < 8; k++)
        {
            x = i + fx[k];
            y = j + fy[k];
            if(x > 0 && x < lm && y > 0 && y < lm && !vis[{x, y}])
            {
                for(p = 0; p < adj[x].size(); p++)
                {
                    val = adj[x][p];
                    if(y >= val.first && y <= val.second)
                    {
                        vis[{x, y}] = true;
                        Q.push({{x, y}, cntt + 1});
                        break;
                    }
                }
            }
        }
    }
 
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ofstream outputf;
    outputf.open("text.txt");
 
    int a, b, c, d, n, m, k, p, f, i, j, mx(0), cnt(0), x, y, last, carry, t, q, xx, oo, dot;
    finl = -1;
    cin>>start_i>>start_j>>final_i>>final_j;
    cin>>n;
    while(n--)
    {
        cin>>k>>i>>j;
        adj[k].push_back({i, j});
    }
    bfs();
    cout<<finl<<"\n";
}
