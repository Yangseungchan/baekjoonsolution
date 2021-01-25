#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct __pos
{
    int x;
    int y;
} Pos;

vector<vector<int>> graph;
vector<vector<bool>> visit;
vector<vector<bool>> done;

int result;

queue<Pos> bfs_queue;
queue<Pos> bfs_1_queue;

void bfs_1(int M, int N) // 1 방문시 done에 기록
{
    int count1 = 0;
    while (!bfs_1_queue.empty())
    {
        Pos index = bfs_1_queue.front();
        bfs_1_queue.pop();
        count1++;

        if (index.x + 1 < M)
        {
            Pos index1 = {index.x + 1, index.y};
            if (graph[index1.x][index1.y] == 1 && done[index1.x][index1.y] == false)
            {
                done[index1.x][index1.y] = true;
                bfs_1_queue.push(index1);
            }
        }
        if (index.y + 1 < N)
        {
            Pos index2 = {index.x, index.y + 1};
            if (graph[index2.x][index2.y] == 1 && done[index2.x][index2.y] == false)
            {
                done[index2.x][index2.y] = true;
                bfs_1_queue.push(index2);
            }
        }
        if (index.x - 1 >= 0)
        {
            Pos index3 = {index.x - 1, index.y};
            if (graph[index3.x][index3.y] == 1 && done[index3.x][index3.y] == false)
            {
                done[index3.x][index3.y] = true;
                bfs_1_queue.push(index3);
            }
        }
        if (index.y - 1 >= 0)
        {
            Pos index4 = {index.x, index.y - 1};
            if (graph[index4.x][index4.y] == 1 && done[index4.x][index4.y] == false)
            {
                done[index4.x][index4.y] = true;
                bfs_1_queue.push(index4);
            }
        }
    }
    result++;
}

void bfs(int M, int N)
{
    while (!bfs_queue.empty())
    {
        Pos index = bfs_queue.front();
        bfs_queue.pop();

        if (index.x + 1 < M)
        {
            Pos index1 = Pos{index.x + 1, index.y};
            if (visit[index1.x][index1.y] == false)
            {
                if (graph[index1.x][index1.y] == 1 && done[index1.x][index1.y] == false)
                {
                    bfs_1_queue.push(index1);
                    done[index1.x][index1.y] = true;
                    bfs_1(M, N);
                }
                bfs_queue.push(index1);
                visit[index1.x][index1.y] = true;
            }
        }
        if (index.y + 1 < N)
        {
            Pos index2 = Pos{index.x, index.y + 1};
            if (visit[index2.x][index2.y] == false)
            {
                if (graph[index2.x][index2.y] == 1 && done[index2.x][index2.y] == false)
                {
                    bfs_1_queue.push(index2);
                    done[index2.x][index2.y] = true;
                    bfs_1(M, N);
                }
                bfs_queue.push(index2);
                visit[index2.x][index2.y] = true;
            }
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int test_case, M, N, K, x, y; // M = 가로길이, N = 세로길이, K = 배추 개수
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        result = 0;
        cin >> M >> N >> K;
        graph = vector<vector<int>>(M, vector<int>(N, 0)); // graph[M][N]
        visit = vector<vector<bool>>(M, vector<bool>(N, false));
        done = visit;

        for (int j = 0; j < K; j++)
        {
            cin >> x >> y;
            graph[x][y] = 1;
        }
        Pos index = {0, 0};
        visit[0][0] = true;
        bfs_queue.push(index);
        if (graph[0][0] == 1)
        {
            bfs_1_queue.push(index);
            done[0][0] = true;
            bfs_1(M, N);
        }
        bfs(M, N);

        cout << result << '\n';
    }
    return 0;
}