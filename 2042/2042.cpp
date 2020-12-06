#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

typedef struct __cmd
{
    int cmd_type;
    int cmd_one;
    ll cmd_two;
} Command;

ll init(vector<ll> &tree, vector<ll> &numbers, int start, int end, int node)
{

    if (start == end)
    {
        return tree[node] = numbers[start];
    }
    int mid = (start + end) / 2;

    return tree[node] = init(tree, numbers, start, mid, 2 * node) + init(tree, numbers, mid + 1, end, 2 * node + 1);
}

void update(vector<ll> &tree, int start, int end, int node, int index, ll diff)
{
    if (!(start <= index && index <= end))
    {
        return;
    }

    tree[node] += diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(tree, start, mid, 2 * node, index, diff);
        update(tree, mid + 1, end, 2 * node + 1, index, diff);
    }
}

ll sum(vector<ll> &tree, int start, int end, int node, int sum_start, int sum_end)
{
    if (sum_end < start || end < sum_start)
    {
        return 0;
    }
    if (sum_start <= start && end <= sum_end)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return sum(tree, start, mid, 2 * node, sum_start, sum_end) + sum(tree, mid + 1, end, 2 * node + 1, sum_start, sum_end);
}

void print_tree(vector<ll> &tree)
{
    for (int i = 1; i < tree.size(); i++)
    {
        cout << tree[i] << ' ';
    }
    cout << '\n';
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num_n, num_change, num_sum, temp, tree_size, i, tmp_a, tmp_b;
    ll tmp_c;
    vector<ll> numbers;
    vector<ll> seg_tree;
    vector<Command> cmd_arr;

    cin >> num_n >> num_change >> num_sum;
    temp = (int)ceil(log2(num_n));
    tree_size = 1 << (temp + 1);

    seg_tree.assign(tree_size, 0);
    seg_tree[0] = 0;

    for (i = 1; i <= num_n; i++)
    {
        cin >> temp;
        numbers.push_back(temp);
    }
    init(seg_tree, numbers, 0, num_n - 1, 1);

    for (i = 0; i < num_change + num_sum; i++)
    {
        cin >> tmp_a >> tmp_b >> tmp_c;
        cmd_arr.push_back({tmp_a, tmp_b, tmp_c});
    }

    for (i = 0; i < num_change + num_sum; i++)
    {
        tmp_b = cmd_arr[i].cmd_one;
        tmp_c = cmd_arr[i].cmd_two;
        if (cmd_arr[i].cmd_type == 1)
        {
            update(seg_tree, 0, num_n - 1, 1, tmp_b - 1, tmp_c - numbers[tmp_b - 1]);
            numbers[tmp_b - 1] = tmp_c;
        }
        else
        {
            cout << sum(seg_tree, 0, num_n - 1, 1, tmp_b - 1, tmp_c - 1) << '\n';
        }
    }

    return 0;
}
