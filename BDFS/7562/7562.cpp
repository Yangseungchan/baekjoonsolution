#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>

#define NOT_VISIT -1

using namespace std;

typedef struct __pos
{
    int x;
    int y;
    int dist;
} Pos;

vector<vector<int>> visit;
queue<Pos> bfs_queue;
int N, fin_x, fin_y;
int result;

void bfs()
{
    result = INT_MAX;
    while (!bfs_queue.empty())
    {
        Pos index = bfs_queue.front();
        bfs_queue.pop();

        if (index.x == fin_x && index.y == fin_y)
        {
            result = min(result, index.dist);
        }

        stack<Pos> index_list;
        Pos index1 = {index.x + 2, index.y + 1, index.dist + 1};
        Pos index2 = {index.x + 2, index.y - 1, index.dist + 1};
        Pos index3 = {index.x - 2, index.y + 1, index.dist + 1};
        Pos index4 = {index.x - 2, index.y - 1, index.dist + 1};
        Pos index5 = {index.x + 1, index.y + 2, index.dist + 1};
        Pos index6 = {index.x + 1, index.y - 2, index.dist + 1};
        Pos index7 = {index.x - 1, index.y + 2, index.dist + 1};
        Pos index8 = {index.x - 1, index.y - 2, index.dist + 1};
        index_list.push(index1);
        index_list.push(index2);
        index_list.push(index3);
        index_list.push(index4);
        index_list.push(index5);
        index_list.push(index6);
        index_list.push(index7);
        index_list.push(index8);

        while (!index_list.empty())
        {
            Pos target = index_list.top();
            index_list.pop();
            if (target.x >= 0 && target.x < N && target.y >= 0 && target.y < N)
            {
                if (visit[target.x][target.y] == NOT_VISIT || visit[target.x][target.y] > target.dist)
                {
                    visit[target.x][target.y] = target.dist;
                    bfs_queue.push(target);
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

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        int start_x, start_y;
        cin >> N;
        visit = vector<vector<int>>(N, vector<int>(N, NOT_VISIT));
        cin >> start_x >> start_y;
        cin >> fin_x >> fin_y;

        while (!bfs_queue.empty())
        {
            bfs_queue.pop();
        }

        Pos start = {start_x, start_y, 0};
        visit[start_x][start_y] = 0;
        bfs_queue.push(start);
        bfs();
        cout << result << '\n';
    }

    return 0;
}