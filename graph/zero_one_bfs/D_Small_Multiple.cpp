#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl '\n'
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl        
#define no cout << "NO" << endl          
#define M 1000000007                     
#define lcm(a, b) a *b / gcd(a, b)       
#define memz(a) memset(a, 0, sizeof(a))  
#define memn(a) memset(a, -1, sizeof(a)) 
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
void bfs(ll n)
{
    vector<ll>vis(n+1,0);
    deque<pair<ll,ll>>q;
    q.push_back({0,0});
    while(q.size())
    {
        pair<ll,ll>par=q.front();
        q.pop_front();
        if(par.first==0&&par.second!=0)
        {
            cout<<par.second<<endl;
            return;
        }
        else if(vis[par.first]);
        else
        {
            vis[par.first]=1;
            if(par.first!=0)q.push_front({(par.first*10)%n,par.second});
            q.push_back({(par.first*10+1)%n,par.second+1});
        }
    }
    cout<<-1<<endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    bfs(n);
}