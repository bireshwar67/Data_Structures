#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;
};

struct Edge
{
    int u, v;
    double weight;
};

struct DisjointSet
{
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

double calculateDistance(const Point &p1, const Point &p2)
{
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return (dx * dx + dy * dy);
}

double minimumWireLength(int N, const vector<Point> &bulbs)
{
    vector<Edge> edges;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            double distance = calculateDistance(bulbs[i], bulbs[j]);
            edges.push_back({i, j, distance});
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    DisjointSet dsu(N);
    double totalLength = 0;
    int numEdgesAdded = 0;
    for (const auto &edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        if (dsu.find(u) != dsu.find(v))
        {
            dsu.unite(u, v);
            totalLength += edge.weight;
            numEdgesAdded++;
            if (numEdgesAdded == N - 1) // All bulbs are connected
                break;
        }
    }

    return totalLength;
}

int main()
{
    int N;
    cin >> N;
    vector<Point> bulbs(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> bulbs[i].x >> bulbs[i].y;
    }
    double result = minimumWireLength(N, bulbs);
    cout << result << endl;
    return 0;
}