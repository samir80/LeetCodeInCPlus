#include "stdafx.h"
#include "Solution.h"
#include <vector>
#include <iostream>
using namespace std;


int main()
{
    vector<int> pile;
    pile.push_back(3);
    pile.push_back(1);
    pile.push_back(4);
    pile.push_back(2);

    Solution sln;
    sln.SortTheCake(pile);
    for (int i = 0; i < pile.size(); i++)
        cout << pile[i] << endl;
    getchar();
    return 0;
}
