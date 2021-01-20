#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _edge
{
    int u;
    int v;
    int weight;
} Edge;

vector<Edge> edge;
vector<int> root;

bool cmp_edge(Edge n1, Edge n2)
{
    if (n1.weight < n2.weight)
    {
        return true;
    }
    return false;
}

Edge setEdge(int u, int v, int weight)
{
    Edge e;
    e.u = u;
    e.v = v;
    e.weight = weight;
    return e;
}

int find(int idx) // idx가 속한 집합의 대푯값(부모값) 반환
{
    if (root[idx] == idx)
        return idx;
    else
        return root[idx] = find(root[idx]); // 매번 재귀함수가 끝날때마다 부모노드를 재설정 -> 균형잡기
}

bool union_set(int u, int v)
{
    int u_p = find(u);
    int v_p = find(v);
    if (u_p == v_p)
        return false;
    root[u_p] = v_p;
    return true;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int V, E, u, v, w;
    int sum = 0;

    cin >> V >> E;
    // graph = vector<vector<int>>(V + 1, vector<int>(V + 1, NULL_VAL));
    root = vector<int>(V + 1);

    for (int i = 0; i < V + 1; i++)
    {
        root[i] = i;
    }
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        Edge e = setEdge(u, v, w);
        edge.push_back(e);
    } // Create given graph

    sort(edge.begin(), edge.end(), cmp_edge);

    for (int i = 0; i < E; i++)
    {
        if (union_set(edge[i].u, edge[i].v))
        {
            sum += edge[i].weight;
        }
    }
    cout << sum << '\n';

    return 0;
}