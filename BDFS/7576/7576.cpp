#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct __pos
{
    int x;
    int y;
    int days;
} Pos;

int result, fresh_tmt;
int M, N; // M = 가로길이(j), N = 세로길이(i)
vector<vector<int>> graph;
vector<vector<bool>> visit;
queue<Pos> bfs_queue;

bool check_index(Pos index) // 방문 가능 여부 확인
{
    int x = index.x;
    int y = index.y;
    if (visit[x][y] == false && graph[x][y] == 0)
    {
        return true;
    }
    return false;
}

void bfs()
{
    while (!bfs_queue.empty())
    {
        Pos index = bfs_queue.front();
        bfs_queue.pop();
        // result값 반영
        result = max(result, index.days);

        if (index.x + 1 < N)
        {
            Pos index1 = Pos{index.x + 1, index.y, index.days + 1};
            if (check_index(index1))
            {
                bfs_queue.push(index1);
                graph[index1.x][index1.y] = 1;
                visit[index1.x][index1.y] = true;
                fresh_tmt--;
            }
        }
        if (index.x - 1 >= 0)
        {
            Pos index1 = Pos{index.x - 1, index.y, index.days + 1};
            if (check_index(index1))
            {
                bfs_queue.push(index1);
                graph[index1.x][index1.y] = 1;
                visit[index1.x][index1.y] = true;
                fresh_tmt--;
            }
        }
        if (index.y + 1 < M)
        {
            Pos index1 = Pos{index.x, index.y + 1, index.days + 1};
            if (check_index(index1))
            {
                bfs_queue.push(index1);
                graph[index1.x][index1.y] = 1;
                visit[index1.x][index1.y] = true;
                fresh_tmt--;
            }
        }
        if (index.y - 1 >= 0)
        {
            Pos index1 = Pos{index.x, index.y - 1, index.days + 1};
            if (check_index(index1))
            {
                bfs_queue.push(index1);
                graph[index1.x][index1.y] = 1;
                visit[index1.x][index1.y] = true;
                fresh_tmt--;
            }
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int input;
    cin >> M >> N;

    graph = vector<vector<int>>(N, vector<int>(M, 0));
    visit = vector<vector<bool>>(N, vector<bool>(M));
    result = -1;
    fresh_tmt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> input;
            if (input == 1)
            {
                Pos pos = {i, j, 0};
                bfs_queue.push(pos);
                visit[i][j] = true;
            }
            if (input == 0)
            {
                ++fresh_tmt;
            }
            graph[i][j] = input;
        }
    }

    if (!bfs_queue.empty())
        bfs();
    if (fresh_tmt > 0)
    {
        result = -1;
    }
    cout << result << '\n';

    return 0;
}