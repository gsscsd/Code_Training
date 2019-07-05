/**
 * 线段树的模板例子
 * 线段树本质是一个完全二叉树，因此可以是使用数组来表示
 * 总结起来就是三个函数，建树，更新树，查询树，注意应该使用
 * 合适的数据结构来构建线段树，并且需要考虑节点与节点的关联
*/
// 区间和例子

#include <bits/stdc++.h>

using namespace std;

#define max_n 1000

// 建树，nums是原始数组，tree是线段树，node是树的位置，left和right是区间边界
// 建树的过程是一个递归的过程
void build_tree(int *nums, int *tree, int node, int left, int right)
{
    // 递归出口
    if (left == right)
        tree[node] = nums[left];
    else
    {
        // 计算中间结点的
        int mid = (left + right) >> 1;
        int left_node = (node << 1) + 1;
        int right_node = (node << 1) + 2;
        // 递归的左子树构建
        build_tree(nums, tree, left_node, left, mid);
        // 递归的右子树构建
        build_tree(nums, tree, right_node, mid + 1, right);
        // 记录当期区间和
        tree[node] = tree[left_node] + tree[right_node];
    }
}

// 更新树，idx代表更改编号idex，val更新的值
void update_tree(int *nums, int *tree, int node, int left, int right, int idx, int val)
{
    // 递归出口
    if (left == right)
    {
        nums[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (left + right) >> 1;
        int left_node = (node << 1) + 1;
        int right_node = (node << 1) + 2;
        // 判断idx在哪一个区间范围内
        if (idx >= left && idx <= mid)
            update_tree(nums, tree, left_node, left, mid, idx, val);
        else
            update_tree(nums, tree, right_node, mid + 1, right, idx, val);
        // 记录当期区间和
        tree[node] = tree[left_node] + tree[right_node];
    }
}

// 区间查询
int query_tree(int *nums, int *tree, int node, int left, int right, int L, int R)
{
    // 递归边界
    if (R < left || L > right)
        return 0;
    else if (L <= left && right <= R)
        return tree[node];
    else if (left == right)
        return tree[node];
    else
    {
        int mid = (left + right) >> 1;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        // 左子树区间查询和
        int sum_left = query_tree(nums, tree, left_node, left, mid, L, R);
        // 右子树区间查询和
        int sum_right = query_tree(nums, tree, right_node, mid + 1, right, L, R);
        return sum_left + sum_right;
    }
}

int main()
{

    const int n = 6;
    int nums[n] = {1, 3, 5, 7, 9, 11};
    // 预定义一个tree，每个元素代表区间和
    // 下标是在树上的位置，0代表根节点
    int tree[max_n] = {0};

    build_tree(nums, tree, 0, 0, n - 1);
    for_each(tree, tree + 2 * n + 3, [](int i) { cout << " the tree nums is " << i << endl; });
    cout << "---------------------------------------" << endl;

    update_tree(nums, tree, 0, 0, n - 1, 4, 6);
    for_each(tree, tree + 2 * n + 3, [](int i) { cout << " the tree nums is " << i << endl; });
    cout << "---------------------------------------" << endl;

    int sum = query_tree(nums, tree, 0, 0, n - 1, 2, 5);
    cout << "the sum is " << sum << endl;
    cout << "---------------------------------------" << endl;
    return 0;
}
