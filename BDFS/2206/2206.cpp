#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct __pos
{
    int x;
    int y;
    int dist;
    bool wall; // true = wall을 뚫은적 있다, false = 뚫은적 없다
} Pos;

typedef pair<bool, bool> pbb; // (f,f) = 방문한적없음, (t,f) = 폭탄사용 한적없으면서 방문, (f,t) = 폭탄 사용한적있으면서 방문, (t, t) = 둘 다 방문

vector<vector<bool>> graph; // false = 0, true= 1; graph[x][y]
vector<vector<pbb>> visit;  // 0 = not visited, 1 = visited by the way which has not used bomb, 2 = visited by the way which has used bomb, 3 = both visited
queue<Pos> bfs_queue;
int result = -1;

int N, M;

void bfs()
{
    while (!bfs_queue.empty())
    {
        queue<Pos> pos_container;
        Pos parent = bfs_queue.front();
        bfs_queue.pop();
        if (parent.x == N - 1 && parent.y == M - 1)
        {
            if (result == -1)
            {
                result = parent.dist;
            }
            else
            {
                result = min(parent.dist, result);
            }
        }

        if (parent.x + 1 < N)
        {
            Pos child = {parent.x + 1, parent.y, parent.dist + 1, parent.wall};
            pos_container.push(child);
        }
        if (parent.x - 1 >= 0)
        {
            Pos child = {parent.x - 1, parent.y, parent.dist + 1, parent.wall};
            pos_container.push(child);
        }
        if (parent.y + 1 < M)
        {
            Pos child = {parent.x, parent.y + 1, parent.dist + 1, parent.wall};
            pos_container.push(child);
        }
        if (parent.y - 1 >= 0)
        {
            Pos child = {parent.x, parent.y - 1, parent.dist + 1, parent.wall};
            pos_container.push(child);
        }
        while (!pos_container.empty())
        {
            Pos child = pos_container.front();
            pos_container.pop();
            if (graph[child.x][child.y] == true) // 벽을 뚫어야한다
            {
                if (child.wall == false)
                {
                    child.wall = true;
                    bfs_queue.push(child);
                }
            }
            else // 벽을 안뚫어도 될때
            {
                if (visit[child.x][child.y].first == true || visit[child.x][child.y].second == true) // 방문한 적 있다
                {
                    if (visit[child.x][child.y].first == false) // 폭탄을 사용해서 방문한 적만 있다
                    {
                        if (child.wall == false) // 폭탄을 사용하지 않았으면 -> 방문 가능
                        {
                            visit[child.x][child.y].first = true;
                            bfs_queue.push(child);
                        }
                    }
                    else if (visit[child.x][child.y].second == false) // 폭탄을 사용하지 않고 방문한 적만 있다
                    {
                        if (child.wall == true) // 폭탄을 사용해봤다면 -> 방문가능
                        {
                            visit[child.x][child.y].second = true;
                            bfs_queue.push(child);
                        }
                    }
                }
                else // 방문한 적 없다
                {
                    if (child.wall == true) // 폭탄 쓴적 있다
                    {
                        visit[child.x][child.y].second = true;
                    }
                    else
                    { // 폭탄 쓴적 없다
                        visit[child.x][child.y].first = true;
                    }
                    bfs_queue.push(child);
                }
            }
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    char input;
    cin >> N >> M;

    graph = vector<vector<bool>>(N, vector<bool>(M, false));
    visit = vector<vector<pbb>>(N, vector<pbb>(M, pbb(false, false)));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> input;
            if (input == '1')
            {
                graph[i][j] = true;
            }
            else if (input == '\n')
            {
                j--;
                continue;
            }
        }
    }
    Pos start = {0, 0, 1, false};
    bfs_queue.push(start);
    visit[0][0].first = true;
    bfs();

    cout << result << '\n';

    return 0;
}

// 풀어도 다른 솔루션 보기