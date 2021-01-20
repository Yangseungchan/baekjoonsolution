#include <iostream>
#include <vector>

using namespace std;

vector<int> root;

int find(int idx) // idx가 속한 집합의 대푯값(부모값) 반환
{
    if (root[idx] == idx)
        return idx;
    else
        return root[idx] = find(root[idx]); // 매번 재귀함수가 끝날때마다 부모노드를 재설정 -> 균형잡기
}

void union_set(int u, int v)
{
    int u_p = find(u);
    int v_p = find(v);
    if (u_p == v_p)
        return;
    root[u_p] = v_p;
}

bool check_same(int u, int v)
{
    int u_p = find(u);
    int v_p = find(v);
    if (u_p == v_p)
        return true;
    return false;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int size, cal_num, type, u, v;

    cin >> size >> cal_num;
    size += 1;
    root = vector<int>(size);

    for (int i = 0; i < size; i++)
    {
        root[i] = i;
    }

    for (int i = 0; i < cal_num; i++)
    {
        cin >> type >> u >> v;
        switch (type)
        {
        case 0:
            union_set(u, v);
            break;
        case 1:
            if (check_same(u, v))
                cout << "YES\n";
            else
                cout << "NO\n";
            break;
        default:
            break;
        }
    }

    return 0;
}