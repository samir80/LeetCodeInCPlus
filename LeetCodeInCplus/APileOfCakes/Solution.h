#pragma once
#include <vector>
#include <algorithm>
using namespace std;

typedef struct maxCake_t {
    int index;
    int max;
}MaxCake;
class Solution
{
public:
    Solution();
    ~Solution();

    void SortTheCake(vector<int>& CakePile);
};
