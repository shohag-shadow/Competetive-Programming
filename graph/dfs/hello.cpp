#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
long long int dx[]={1,0,-1,0,1,-1,-1,1};
long long int dy[]={0,1,0,-1,1,1,-1,-1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n;
    cin>>n;
    long long int a[n];
    for(int i = 0; i < (n); i++)   cin >> a[i]; 
}