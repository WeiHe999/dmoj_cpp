#include <bits/stdc++.h>
using namespace std;

int find_root(int node, vector <int> &roots)
{
    if (node != roots[node]) roots[node] = find_root(roots[node], roots);
    return roots[node];
}

bool unify(int node1, int node2, vector <int> &roots)
{
    int root1 = find_root(node1, roots), root2 = find_root(node2, roots);
    if (root1 == root2) return true;
    roots[root2] = root1;
    return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    vector <int> roots(n + 1);
    vector <int> results;
    for (int x = 1; x <= n; x++) roots[x] = x;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b;
        if (!unify(a, b, roots)) results.emplace_back(x + 1);
    }
    if (results.size() < n - 1) cout << "Disconnected Graph\n";
    else for (auto x : results) cout << x << "\n";
}
