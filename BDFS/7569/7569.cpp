#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct __pos
{
    int x;
    int y;
    int z;
    int days;
} Pos;

int tmt_box[100][100][100];
bool visit[100][100][100];
int fresh_tmt;
int result;
int M, N, H; // tmt_box[H][N][M] or visit[H][N][M]
queue<Pos> bfs_queue;

bool check_index(Pos index) // 방문 가능 여부 확인
{
    int x = index.x;
    int y = index.y;
    int z = index.z;
    if (visit[x][y][z] == false && tmt_box[x][y][z] == 0)
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
        result = max(result, index.days);

        if (index.x + 1 < H)
        {
            Pos index1 = Pos{index.x + 1, index.y, index.z, index.days + 1};
            if (check_index(index1))
            {
                bfs_queue.push(index1);
                tmt_box[index1.x][index1.y][index1.z] = 1;
                visit[index1.x][index1.y][index1.z] = true;
                fresh_tmt--;
            }
        }
        if (index.x - 1 >= 0)
        {
            Pos index1 = Pos{index.x - 1, index.y, index.z, index.days + 1};
            if (check_index(index1))
            {
                bfs_queue.push(index1);
                tmt_box[index1.x][index1.y][index1.z] = 1;
                visit[index1.x][index1.y][index1.z] = true;
                fresh_tmt--;
            }
        }
        if (index.y + 1 < N)
        {
            Pos index1 = Pos{index.x, index.y + 1, index.z, index.days + 1};
            if (check_index(index1))
            {
                bfs_queue.push(index1);
                tmt_box[index1.x][index1.y][index1.z] = 1;
                visit[index1.x][index1.y][index1.z] = true;
                fresh_tmt--;
            }
        }
        if (index.y - 1 >= 0)
        {
            Pos index1 = Pos{index.x, index.y - 1, index.z, index.days + 1};
            if (check_index(index1))
            {
                bfs_queue.push(index1);
                tmt_box[index1.x][index1.y][index1.z] = 1;
                visit[index1.x][index1.y][index1.z] = true;
                fresh_tmt--;
            }
        }
        if (index.z + 1 < M)
        {
            Pos index1 = Pos{index.x, index.y, index.z + 1, index.days + 1};
            if (check_index(index1))
            {
                bfs_queue.push(index1);
                tmt_box[index1.x][index1.y][index1.z] = 1;
                visit[index1.x][index1.y][index1.z] = true;
                fresh_tmt--;
            }
        }
        if (index.z - 1 >= 0)
        {
            Pos index1 = Pos{index.x, index.y, index.z - 1, index.days + 1};
            if (check_index(index1))
            {
                bfs_queue.push(index1);
                tmt_box[index1.x][index1.y][index1.z] = 1;
                visit[index1.x][index1.y][index1.z] = true;
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

    fresh_tmt = 0;
    result = -1;
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> input;
                if (input == 0)
                {
                    ++fresh_tmt;
                }
                else
                {
                    tmt_box[i][j][k] = input;
                }
                if (input == 1)
                {
                    Pos pos = {i, j, k, 0};
                    bfs_queue.push(pos);
                    visit[i][j][k] = true;
                }
            }
        }
    }
    bfs();
    if (fresh_tmt > 0)
    {
        result = -1;
    }
    cout << result << '\n';

    return 0;
}