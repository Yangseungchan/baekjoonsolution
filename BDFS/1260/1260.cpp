
#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int length; // length = N
vector<bool> visit;
vector<vector<int>> graph;
queue<int> bfs_queue;
vector<int> dfs_result;
vector<int> bfs_result;

void dfs(int start)
{
    visit[start] = true;
    dfs_result.push_back(start);
    for (int i = 1; i <= length; i++)
    {
        if (start != i && graph[start][i] == 1 && visit[i] == false)
        {
            dfs(i);
        }
    }
    return;
}

void bfs()
{
    while (!bfs_queue.empty())
    {
        int index = bfs_queue.front();
        bfs_queue.pop();
        bfs_result.push_back(index);
        for (int i = 1; i <= length; i++)
        {
            if (index != i && graph[index][i] == 1 && visit[i] == false)
            {
                bfs_queue.push(i);
                visit[i] = true;
            }
        }
    }
}

void init_visit()
{
    for (int i = 0; i < visit.size(); i++)
    {
        visit[i] = false;
    }
}

void print_vector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
        {
            cout << ' ';
        }
    }
    cout << '\n';
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, V, from, to; // N = # of vertex, M = # of edges, V = # to start

    cin >> N >> M >> V;
    length = N;

    visit = vector<bool>(N + 1, false);
    graph = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    // graph = (Node **)malloc(sizeof(Node *) * (N + 1)); // graph[1] ~ graph[N]

    for (int i = 0; i < M; i++)
    {
        cin >> from >> to;
        graph[from][to] = graph[to][from] = 1;
    }
    dfs(V);
    print_vector(dfs_result);
    init_visit();
    bfs_queue.push(V);
    visit[V] = true;
    bfs();
    print_vector(bfs_result);

    return 0;
}