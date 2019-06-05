#include <bits/stdc++.h>


using namespace std;


template<typename T>
void printer(const T& val)
{
    cout << val << endl;
}


// 1.冒泡排序
void buble_sort(vector<int> &nums,int left,int right)
{
    if(left >= right) return;
    for(int i = left ;i < right;i++)
    {
        for(int j = i + 1;j < right;j++)
        {
            if(nums[i] > nums[j])
                swap(nums[j],nums[i]);
        }
    }
}

// 2. 选择排序
void select_sort(vector<int> &nums,int left,int right)
{
    if(left >= right) return;

    for(int i = left;i < right;i++)
    {
        // 注意c++11 auto自动分配类型
        auto min_num = min_element(nums.begin() + i,nums.begin() + right);
        int min_num_index = distance(nums.begin(),min_num);
        swap(nums[min_num_index],nums[i]);
    }

}

// 3. 直接插入排序
void insert_sort(vector<int> &nums,int left,int right)
{
    if(left >= right) return;
    for(int i = left + 1;i < right;i++)
    {
        int j = i - 1;
        int tmp = nums[i];
        while(j >= left && nums[j] > tmp)
            nums[j + 1] = nums[j--];
        nums[j + 1] = tmp;
    }
}





int main()
{
    const int n = 7;
    vector<int> nums = {6,1,2,1,3,5,4};
    cout << "----------->>>>>>> befor sort ---------------->>>>" << endl;
    // 第一种遍历方法
    // for_each(nums.cbegin(), nums.cend(), printer<int>);
    // C++ 11
    for(auto i : nums) cout << i << endl;

    // 开始排序
    // buble_sort(nums,0,n);
    // select_sort(nums,0,n);
    insert_sort(nums,0,n);

    cout << "----------->>>>>>> after sort ---------------->>>>" << endl;
    // 第一种遍历方法
    for_each(nums.cbegin(), nums.cend(), printer<int>);

    return 0;
}