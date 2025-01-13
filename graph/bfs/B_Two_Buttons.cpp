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
vector<ll>graph[20001];
ll inf=100000000000;
ll dis[20001];
void bfs(ll source)
{
    dis[source]=0;
    queue<ll>q;
    q.push(source);
    while(q.size())
    {
        ll par=q.front();
        q.pop();
        for(auto child:graph[par])
        {
            if(dis[child]>dis[par]+1)
            {
                dis[child]=dis[par]+1;
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
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<20000;i++)dis[i]=inf;
    for(int i=1;i<=10000;i++)
    {
        graph[i].push_back(2*i);
        graph[i].push_back(i-1);
    }
    for(int i=10001;i<=20000;i++)
    {
        graph[i].push_back(i-1);
    }
    bfs(n);
    cout<<dis[m]<<endl;
}