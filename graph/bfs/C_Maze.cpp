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
ll n,m,k;
string maze[502];
vector<pair<ll,ll>>moves={{-1,0},{1,0},{0,-1},{0,1}};
void bfs(ll x,ll y)
{
    stack<pair<ll,ll>>st;
    vector<vector<ll>>vis(n,vector<ll>(m,0));
    vis[x][y]=1;
    queue<pair<ll,ll>>q;
    q.push({x,y});
    while(q.size())
    {
        pair<ll,ll>par=q.front();
        st.push(par);
        //cout<<par.first<<" "<<par.second<<endl;
        q.pop();
        for(auto u:moves)
        {
            pair<ll,ll> child={par.first+u.first,par.second+u.second};
            
            if(child.first>=0&&child.first<n&&child.second>=0&&child.second<m)
            {
                if(vis[child.first][child.second]==0&&maze[child.first][child.second]=='.')
                {
                    vis[child.first][child.second]=1;
                    q.push(child);
                }
            }
        }
    }
    while(k)
    {
        pair<ll,ll>x=st.top();
        st.pop();
        k--;
        maze[x.first][x.second]='X';
    }
    

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)cin>>maze[i];
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maze[i][j]=='.')
            {
                bfs(i,j);
                flag=true;
                break;
            }
            
        }
        if(flag)break;
    }
    for(int i=0;i<n;i++)
    cout<<maze[i]<<endl;

}