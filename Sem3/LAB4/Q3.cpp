#include <iostream>
#include <set>
#include <vector>
using namespace std;

void permutation(vector<int> nums, set<vector<int>> &s, int idx)
{
    if (idx == nums.size())
    {
        s.insert(nums);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        permutation(nums, s, idx + 1);
        swap(nums[idx], nums[i]);
    }
}

void printArr(vector<int> &arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums;
    set<vector<int>> s;
    bool quit = false;
    int num = 0;
    while (!quit)
    {
        cout << "Enter Number To insert (-1 to quit)" << endl;
        cin >> num;
        if (num == -1)
        {
            quit = true;
        }
        else{
            nums.push_back(num);

        }
    }
    cout << endl;
    permutation(nums, s, 0);
    cout << "size : " << s.size() << endl;
    for(auto it : s){
        printArr(it);
    }
    return 0;
}