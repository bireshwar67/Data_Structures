#include <iostream>
#include <vector>

using namespace std;

class DisjointSetUnion
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSetUnion(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV)
            return;
        if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};

int main()
{
    int N, K;
    cin >> N >> K;

    DisjointSetUnion dsu(N);

    for (int i = 0; i < K; ++i)
    {
        int empire_i, empire_j;
        cin >> empire_i >> empire_j;
        dsu.merge(empire_i, empire_j);
    }

    int distinctEmpires = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (dsu.find(i) == i)
            distinctEmpires++;
    }

    cout << distinctEmpires << endl;

    return 0;
}