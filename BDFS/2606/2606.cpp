#include <iostream>
#include <vector>
#include <queue>
// #include <cstdio>
#include <algorithm>

using namespace std;

typedef struct __pos
{
    int x;
    int y;
} Pos;

vector<vector<bool>> visit; // bfs상에서의 방문 여부확인용
vector<vector<bool>> done;  // bfs_1 상에서의 1들에 대한 방문 여부 확인용
vector<vector<int>> graph;  // 실제 그래프
vector<int> results;        // 1탐색 결과를 담아내는 벡터

queue<Pos> bfs_queue;
queue<Pos> bfs_1_queue;

void bfs_1(int size) // 1 방문시 done에 기록
{
    int count1 = 0;
    while (!bfs_1_queue.empty())
    {
        Pos index = bfs_1_queue.front();
        bfs_1_queue.pop();
        count1++;

        if (index.x + 1 < size)
        {
            Pos index1 = {index.x + 1, index.y};
            if (graph[index1.x][index1.y] == 1 && done[index1.x][index1.y] == false)
            {
                done[index1.x][index1.y] = true;
                bfs_1_queue.push(index1);
            }
        }
        if (index.y + 1 < size)
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
    results.push_back(count1);
}

void bfs(int size)
{
    while (!bfs_queue.empty())
    {
        Pos index = bfs_queue.front();
        bfs_queue.pop();

        if (index.x + 1 < size)
        {
            Pos index1 = Pos{index.x + 1, index.y};
            if (visit[index1.x][index1.y] == false)
            {
                if (graph[index1.x][index1.y] == 1 && done[index1.x][index1.y] == false)
                {
                    bfs_1_queue.push(index1);
                    done[index1.x][index1.y] = true;
                    bfs_1(size);
                }
                bfs_queue.push(index1);
                visit[index1.x][index1.y] = true;
            }
        }
        if (index.y + 1 < size)
        {
            Pos index2 = Pos{index.x, index.y + 1};
            if (visit[index2.x][index2.y] == false)
            {
                if (graph[index2.x][index2.y] == 1 && done[index2.x][index2.y] == false)
                {
                    bfs_1_queue.push(index2);
                    done[index2.x][index2.y] = true;
                    bfs_1(size);
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

    char ch;
    int N;
    cin >> N;

    graph = vector<vector<int>>(N, vector<int>(N));
    visit = vector<vector<bool>>(N, vector<bool>(N, false));
    done = visit;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> ch;
            if (ch == '\n')
            {
                // skip;
                j--;
                continue;
            }
            int num = ch - '0';
            graph[i][j] = num;
        }
    }
    Pos index = {0, 0};
    visit[0][0] = true;
    bfs_queue.push(index);
    if (graph[0][0] == 1)
    {
        Pos index = {0, 0};
        bfs_1_queue.push(index);
        done[0][0] = true;
        bfs_1(N);
    }
    bfs(N);

    sort(results.begin(), results.end());
    cout << results.size() << '\n';
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << '\n';
    }

    return 0;
}