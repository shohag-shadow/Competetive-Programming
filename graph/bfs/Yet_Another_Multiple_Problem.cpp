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
ll ok[10];
void bfs(ll n)
{
    queue<ll>q;
    vector<bool>vis(n,0);
    vector<pair<ll,ll>>parent(n);
    vis[0]=1;
    q.push(0);
    while(q.size())
    {
        ll par=q.front();
        q.pop();
        //cout<<par<<endl;
        for(int i=(par==0);i<10;i++)
        {
            if(ok[i])
            {
                ll child=(par*10+i)%n;
                if(child==0)
                {
                    string ans;
                    ans.push_back(i+'0');
                    while(par>0)
                    {
                        ans.push_back(parent[par].second+'0');
                        par=parent[par].first;
                    }
                    reverse(all(ans));
                    cout<<ans<<endl;
                    return;
                }
                else if(vis[child]==0)
                {
                    vis[child]=1;
                    parent[child]={par,i};
                    q.push(child);
                }
            }
        }
    }
    cout<<-1<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    ll cs=1;
    while(cin>>n)
    {
        cout<<"Case "<<cs++<<": ";
        ll m;
        cin>>m;
        for(int i=0;i<10;i++)ok[i]=1;
        for(int i=0;i<m;i++)
        {
            ll k;
            cin>>k;
            ok[k]=0;
        }
        bfs(n);
    }
}