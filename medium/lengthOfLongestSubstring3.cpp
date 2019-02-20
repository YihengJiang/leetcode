//
// Created by jyh on 1/5/2019.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        string tmp;
        for (char &i : s) {//can also do not reference it, i.e. (char i : s), but (char i : s) is dumplicating form s,so revise i will have no effective for s.
            int pos = tmp.find_first_of(i);
            tmp = (pos != string::npos ? tmp.substr(pos + 1) : tmp) + i;
            length = length > tmp.length() ? length : tmp.length();

        }
        return length;
    }

    void allPositionOfSubstring(const string &s, char i, vector<int> &v,int offset=0) {
        /*
         * it is not Question of leetCode, instead, I implemented it for interesting.
         * */
        int currPos = s.find(i);
        if (currPos != string::npos) {
            v.push_back(currPos+offset);
            offset+=(currPos+1);
            string tmp=s.substr(currPos + 1);
            allPositionOfSubstring(tmp, i, v,offset);
        }

    }
};


int main() {
    string input = "pwwkew";
    Solution s;
    int output = s.lengthOfLongestSubstring(input);
    cout << output << endl;
    vector<int> pos;
    char i = 'w';
    s.allPositionOfSubstring(input, i, pos);
    copy(pos.begin(), pos.end(), ostream_iterator<int>(cout, " "));
}