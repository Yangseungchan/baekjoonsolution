#include <iostream>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

void init(vector<int> &h, vector<int> &tree, int node, int start, int end) // node = index of node tree ; start = start index of h
{
    if (start == end)
    {
        tree[node] = start;
        return;
    }
    int mid = (start + end) / 2;
    init(h, tree, 2 * node, start, mid);
    init(h, tree, 2 * node + 1, mid + 1, end);
    if (h[tree[2 * node]] <= h[tree[2 * node + 1]])
    {
        tree[node] = tree[2 * node];
    }
    else
    {
        tree[node] = tree[2 * node + 1];
    }
}

/* function to find minimum height's index in range (i, j) */
int find_min_h_idx(vector<int> &h, vector<int> &tree, int node, int start, int end, int i, int j) // node = tree's node index, (start, end) = tree node's range, (i, j) = range to check for largest area
{
    if (i > end || j < start)
    {
        return -1;
    }
    else if (i <= start && end <= j)
    {
        return tree[node]; // return mimimum height's index of vector h
    }
    int mid = (start + end) / 2;
    int m1 = find_min_h_idx(h, tree, 2 * node, start, mid, i, j);
    int m2 = find_min_h_idx(h, tree, 2 * node + 1, mid + 1, end, i, j);
    if (m1 == -1)
    {
        return m2;
    }
    else if (m2 == -1)
    {
        return m1;
    }
    else
    {
        if (h[m1] <= h[m2])
        {
            return m1;
        }
        else
        {
            return m2;
        }
    }
}

/* function to find largest area in range (start, end); start = leftmost index of range to find max area; end = rightmost index of range to find max area */
ll find_largest_area(vector<int> &h, vector<int> &tree, int start, int end)
{
    int min_idx = find_min_h_idx(h, tree, 1, 0, h.size() - 1, start, end);
    ll area = (long long)(end - start + 1) * (long long)h[min_idx];
    if (start <= min_idx - 1)
    {
        ll temp = find_largest_area(h, tree, start, min_idx - 1);
        if (temp > area)
        {
            area = temp;
        }
    }
    if (min_idx + 1 <= end)
    {
        ll temp = find_largest_area(h, tree, min_idx + 1, end);
        if (temp > area)
        {
            area = temp;
        }
    }
    return area;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int temp, length, tree_len;
    cin >> length;
    while (length > 0)
    {
        vector<int> height(length);
        for (int i = 0; i < length; i++)
        {
            cin >> height[i];
        }
        temp = (int)(ceil(log2(length)));
        tree_len = 1 << (temp + 1);

        vector<int> tree(tree_len);
        init(height, tree, 1, 0, length - 1);
        cout << find_largest_area(height, tree, 0, length - 1) << '\n';
        cin >> length;
    }

    return 0;
}