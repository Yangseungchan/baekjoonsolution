#include <iostream>
#include <vector>

using namespace std;

typedef struct _vertex
{
    int data;
    int color; /* 0 = white, 1 = gray */
} Vertex;

class DFS
{
private:
    vector<Vertex> vtx; // 0을 포함하되, 탐색은 1부터 length까지
    vector<int> queue;
    int length;
    int count;

public:
    DFS(int len, int cnt) : length(len), count(cnt) {}

    void initdata()
    {
        Vertex vertex;
        for (int i = 0; i <= length; i++)
        {
            vertex.data = i;
            vertex.color = 0;
            vtx.push_back(vertex);
        }
    }

    void print_queue()
    {
        for (int i = 0; i < queue.size(); i++)
        {
            cout << queue[i] << " ";
        }
        cout << '\n';
    }

    void pop_vertex(int idx)
    {
        vtx[idx].color = 0;
        if (queue.size() > 0)
            queue.pop_back();
    }

    void dfs_search()
    {
        for (int i = 1; i <= length; i++)
        {
            if (vtx[i].color == 0)
            {
                dfs_visit(i);
                pop_vertex(i);
            }
        }
    }

    void dfs_visit(int start)
    {
        int idx;
        vtx[start].color = 1;
        queue.push_back(start);

        if (queue.size() == count)
        {
            print_queue();
            idx = queue.back();
            pop_vertex(idx);
            return;
        }

        for (int i = 1; i <= length; i++)
        {
            dfs_visit(i);
        }

        pop_vertex(start);
        return;
    }
};

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int len, count;
    cin >> len;
    cin >> count;
    DFS dfs(len, count);

    dfs.initdata();
    dfs.dfs_search();

    return 0;
}