#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

typedef struct __node
{
    int data;
    struct __node *next;
} Node;

Node **graph;
int result;

vector<bool> visit;
queue<int> bfs_queue;

void bfs()
{
    while (!bfs_queue.empty())
    {
        int index = bfs_queue.front();
        // cout << index << "-> ";
        bfs_queue.pop();
        Node *nde = graph[index];
        while (nde != NULL)
        {
            int data = nde->data;
            if (visit[data] == false)
            {
                bfs_queue.push(data);
                result++;
                visit[data] = true;
            }
            nde = nde->next;
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int V, E, from, to; // Vertex = 1~V
    cin >> V >> E;
    result = 0;
    visit = vector<bool>(V + 1, false);
    graph = (Node **)malloc(sizeof(Node *) * (V + 1));
    for (int i = 1; i <= V; i++)
    {
        graph[i] = NULL;
    }
    // 포인터는 = 의 왼쪽에 있냐 오른쪽에 있냐에 따라 역할이 달라진다
    // 왼쪽 => 주솟값을 나타내고, 오른쪽 => 가리키는 대상을 나타낸다
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to;
        Node *nde = (Node *)malloc(sizeof(Node));
        nde->data = to;
        nde->next = graph[from];
        graph[from] = nde;

        Node *nde2 = (Node *)malloc(sizeof(Node));
        nde2->data = from;
        nde2->next = graph[to];
        graph[to] = nde2;
    }
    visit[1] = true;
    bfs_queue.push(1);
    bfs();
    // cout << endl;

    cout << result << '\n';
    return 0;
}