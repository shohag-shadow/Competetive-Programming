#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl '\n'
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define all(v) v.begin(), v.end()
#define pb push_back //
#define mp make_pair
#define fi first                         //
#define se second                        //
#define yes cout << "YES" << endl        //
#define no cout << "NO" << endl          //
#define M 1000000007                     // 1e9+7
#define gcd(a, b) __gcd(a, b)            //
#define lcm(a, b) a *b / gcd(a, b)       //
#define memz(a) memset(a, 0, sizeof(a))  //
#define memn(a) memset(a, -1, sizeof(a)) //
vector<pair<ll,ll>>moves={{0,1},{0,-1},{1,0},{-1,0}};
ll dis[1001][1001];
string maze[1001];
ll x,y,n,m;
bool valid(ll x,ll y)
{
    pair<ll,ll>child={x,y};
    if(child.first>=0&&child.first<n&&child.second>=0&&child.second<m)return true;
    else return false;
}
void bfs()
{
    pair<ll,ll>source={x,y};
    queue<pair<ll,ll>>q;
    dis[source.first][source.second]=0;
    q.push(source);
    while(q.size())
    {
        pair<ll,ll>par=q.front();
        q.pop();
        for(auto u:moves)
        {
            pair<ll,ll>child={par.first+u.first,par.second+u.second};
            if(valid(child.first,child.second)&&maze[child.first][child.second]=='.'&&dis[par.first][par.second]+1<dis[child.first][child.second])
            {
                dis[child.first][child.second]=dis[par.first][par.second]+1;
                q.push(child);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll k;
    cin>>n>>m>>k;
    for(int i=0;i<1001;i++)
    {
        for(int j=0;j<1001;j++)dis[i][j]=1000000000;
    }
    for(int i=0;i<n;i++)
    {
        cin>>maze[i];
        for(int j=0;j<m;j++)
        {
            if(maze[i][j]=='X')
            {
                x=i;
                y=j;
            }
        }
    }
    if(k%2)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    bfs();
    vector<char>path;
    //dlru
    while(k--)
    {
        if(valid(x+1,y)&&dis[x+1][y]<=k)
        {
            x++;
            path.push_back('D');
        }
        else if(valid(x,y-1)&&dis[x][y-1]<=k)
        {
            y--;
            path.push_back('L');
        }
        else if(valid(x,y+1),dis[x][y+1]<=k)
        {
            y++;
            path.push_back('R');
        }
        else if(valid(x-1,y)&&dis[x-1][y]<=k)
        {
            x--;
            path.push_back('U');
        }
        else
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    for(auto u:path)cout<<u;
    cout<<endl;
}