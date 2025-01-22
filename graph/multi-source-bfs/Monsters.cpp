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
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
char p[]={'U','D','L','R'};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    queue<pair<pair<ll,ll>,ll>>q;
    string maze[n];
    char parent[n][m];
    pair<pair<ll,ll>,ll>start;
    ll vis[n][m];
    for(int i=0;i<n;i++)
    {
        cin>>maze[i];
        for(int j=0;j<m;j++)
        {
            if(maze[i][j]=='M')
            {
                q.push({{i,j},0});
                parent[i][j]='s';
                vis[i][j]=0;
            }
            else if(maze[i][j]=='A')
            {
                start={{i,j},1};
                parent[i][j]='s';
                vis[i][j]=1;
            }
            else
            {
                parent[i][j]='M';
                vis[i][j]=2;
            }

        }
    }
    q.push(start);
    pair<pair<ll,ll>,ll>ans={{-1,-1},0};
    while(q.size())
    {
        pair<pair<ll,ll>,ll>par=q.front();
        //cout<<par.first.first<<" "<<par.first.second<<" "<<par.second<<endl;
        q.pop();
        if(par.first.first==0||par.first.first==n-1||par.first.second==0||par.first.second==m-1)
        {
            if(vis[par.first.first][par.first.second]==1)
            {
                ans=par;
                break;
            }
        }
        for(int i=0;i<4;i++)
        {
            ll x=par.first.first+dx[i];
            ll y=par.first.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==2&&maze[x][y]=='.')
            {
                vis[x][y]=par.second;
                parent[x][y]=p[i];
                q.push({{x,y},vis[x][y]});
            }
        }
    }
    ll x=ans.first.first;
    ll y=ans.first.second;
    if(x==-1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    string out;
    while(parent[x][y]!='s')
    {
        out.push_back(parent[x][y]);
        for(int i=0;i<4;i++)
        {
            if(p[i]==parent[x][y])
            {
                x+=(-1)*dx[i];
                y+=(-1)*dy[i];
                break;
            }
        }
    }
    reverse(all(out));
    cout<<out.size()<<endl<<out<<endl;
    
}