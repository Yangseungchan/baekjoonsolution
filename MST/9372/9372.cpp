#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<vector<bool>> graph;
vector<bool> visit;

long long result;

void init(int vertex)
{
    graph = vector<vector<bool>>(vertex + 1, vector<bool>(vertex + 1, false));
    visit = vector<bool>(vertex + 1, false);
}

void dfs(int index)
{
    visit[index] = true;
    int size = visit.size();
    for (int i = 1; i < size; i++)
    {
        if (index == i)
            continue;
        if (graph[index][i] == true && visit[i] == false)
        {

            dfs(i);
            ++result;
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int test_case;

    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        result = 0;
        int vertex, edge;
        cin >> vertex >> edge;
        init(vertex);
        for (int j = 0; j < edge; j++)
        {
            int from, to;
            cin >> from >> to;
            graph[from][to] = graph[to][from] = true;
        }
        dfs(1);
        cout << result << '\n';
    }

    return 0;
}