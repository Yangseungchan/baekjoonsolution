#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef struct __pos
{
    int x;
    int y;
    long long count;
} Pos;

vector<vector<bool>> graph;
vector<vector<bool>> visit;

queue<Pos> bfs_queue;
long long result;
int N, M;

bool check_index(Pos index)
{
    if (index.x >= 1 && index.x <= N && index.y >= 1 && index.y <= M)
    {
        if (graph[index.x][index.y] == true && visit[index.x][index.y] == false)
            return true;
    }
    return false;
}

void set_visit(Pos index)
{
    visit[index.x][index.y] = true;
    return;
}

void bfs1()
{
    while (!bfs_queue.empty())
    {
        Pos index = bfs_queue.front();
        bfs_queue.pop();

        if (index.x == N && index.y == M)
        {
            result = min(result, index.count);
        }

        Pos index1 = {index.x + 1, index.y, index.count};
        Pos index2 = {index.x - 1, index.y, index.count};
        Pos index3 = {index.x, index.y + 1, index.count};
        Pos index4 = {index.x, index.y - 1, index.count};
        if (check_index(index1))
        {
            index1.count++;
            bfs_queue.push(index1);
            set_visit(index1);
        }
        if (check_index(index2))
        {
            index2.count++;
            bfs_queue.push(index2);
            set_visit(index2);
        }
        if (check_index(index3))
        {
            index3.count++;
            bfs_queue.push(index3);
            set_visit(index3);
        }
        if (check_index(index4))
        {
            index4.count++;
            bfs_queue.push(index4);
            set_visit(index4);
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    graph = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
    visit = graph;
    result = LONG_LONG_MAX;

    char ch;
    int num;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> ch;
            if (ch == '\n')
            {
                j--;
                continue;
            }
            num = ch - '0';
            if (num == 1)
                graph[i][j] = true;
        }
    }
    Pos start = {1, 1, 1};
    bfs_queue.push(start);
    set_visit(start);
    bfs1();

    cout << result << '\n';

    return 0;
}