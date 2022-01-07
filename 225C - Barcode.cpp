#include <bits/stdc++.h>
using namespace std;

#define piii pair<pair<int, int>, int>
#define lli long long int
#define white first
#define black second
#define pir pair<int, int>
#define inf 10000000

vector<pir> vec;
map<int, pir> adj;
int dp[1002][3][1002];
int arr[105];

int m, n, x, y;
int lm = 1000000001;
string st;

int solve(int idx, int pxl, int cnt)
{
    if(idx >= m && cnt < x)
        return inf;
    if(idx >= m)
        return 0;
    if(cnt > y)
        return inf;
    if(dp[idx][pxl][cnt] != -1)
        return dp[idx][pxl][cnt];
    int val1(inf), val2(inf);
    if(pxl == 2)
    {
        val1 = adj[idx].black + solve(idx+1, 0, 1);
        val2 = adj[idx].white + solve(idx+1, 1, 1);
    }
    if(pxl == 0)
    {
        if(cnt < x)
            val1 = adj[idx].black + solve(idx+1, 0, cnt + 1);
        else
        {
            val1 = adj[idx].black + solve(idx+1, 0, cnt + 1);
            val2 = adj[idx].white + solve(idx+1, 1, 1);
        }
    }
    if(pxl == 1)
    {
        if(cnt < x)
            val2 = adj[idx].white + solve(idx+1, 1, cnt + 1);
        else
        {
            val1 = adj[idx].black + solve(idx+1, 0, 1);
            val2 = adj[idx].white + solve(idx+1, 1, cnt + 1);
        }
    }
    return dp[idx][pxl][cnt] = min(val1, val2);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ofstream outputf;
    outputf.open("text.txt");

    int i, j, mx(0), last, carry, t;
    bool paisi_g, paisi_s;
    int c, k, l, f, cnt(0), sp(0), sd(0), xc, yc, t1, t2, vp, vd;
    int a, b, d, p, q, r(0), r2(0), g, s;
    char ch;

    cin>>n>>m>>x>>y;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cin>>ch;
            if(ch == '.')
                adj[j].white++;
            else
                adj[j].black++;
        }
    }

    memset(dp, -1, sizeof(dp));
    cout<<solve(0, 2, 0)<<"\n";
}
