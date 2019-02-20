//
// Created by jyh on 1/5/2019.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        /* other for loop writing style:
        for(int i:nums){
            TODO
        }

        vector<int>::iterator i;
        for(i = nums.begin(); i != nums.end(); i++){
            TODO
        }
         */

        map<int, int> value2Ind;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (value2Ind.find(complement) != value2Ind.end()) {
                int tmp1[] = {i, value2Ind[complement]};
                //point:array to vector,we can do like this:
                //vector<int> tmp={*tmp1,*tmp1+1};
                return vector<int>{*tmp1, *(tmp1 + 1)};
            }
            value2Ind[nums[i]] = i;

        }
    }
};


int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution a;
    vector<int> rlt = a.twoSum(nums, target);
    cout << rlt[0] << "  " << rlt[1] << endl;
    return 0;
}