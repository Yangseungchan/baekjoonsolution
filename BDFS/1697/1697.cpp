#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define LIMIT_MAX 100001
#define LIMIT_MIN 0

using namespace std;

typedef struct __node
{
    int pos;
    int sec;
} Node;

queue<Node> bfs_queue;

int pos_map[LIMIT_MAX];
int search_max = LIMIT_MAX - 1;
int max_sec = LIMIT_MAX;
int N, K;

void bfs()
{
    while (!bfs_queue.empty())
    {
        Node nde = bfs_queue.front();
        bfs_queue.pop();
        if (nde.pos - 1 >= LIMIT_MIN)
        {
            Node newnde = {nde.pos - 1, nde.sec + 1};
            if (pos_map[newnde.pos] >= newnde.sec && newnde.sec <= max_sec)
            {
                pos_map[newnde.pos] = newnde.sec;
                bfs_queue.push(newnde);
            }
        }
        if (nde.pos + 1 <= search_max)
        {
            Node newnde = {nde.pos + 1, nde.sec + 1};
            if (pos_map[newnde.pos] >= newnde.sec && newnde.sec <= max_sec)
            {
                pos_map[newnde.pos] = newnde.sec;
                bfs_queue.push(newnde);
            }
        }
        if (nde.pos * 2 <= search_max)
        {
            Node newnde = {nde.pos * 2, nde.sec + 1};
            if (pos_map[newnde.pos] >= newnde.sec && newnde.sec <= max_sec)
            {
                pos_map[newnde.pos] = newnde.sec;
                bfs_queue.push(newnde);
            }
        }
        if (pos_map[K] != LIMIT_MAX)
        {
            max_sec = pos_map[K];
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    // 출발지점에서의 pos_map값 초기화
    // K < 2K < N일 경우 => search_max값이 과연 옳은가?
    if (N != K)
    {
        Node pos = {N, 0};
        pos_map[N] = 0;
        // search_max = min(2 * K, search_max);
        for (int i = 0; i <= search_max; i++)
        {
            pos_map[i] = LIMIT_MAX;
        }
        bfs_queue.push(pos);
        bfs();

        cout << pos_map[K] << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
    return 0;
}