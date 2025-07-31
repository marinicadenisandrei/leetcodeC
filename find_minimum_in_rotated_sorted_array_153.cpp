/* Leetcode - 153. Find Minimum in Rotated Sorted Array (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMin(vector<int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 153. Find Minimum in Rotated Sorted Array (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{3,4,5,1,2},{4,5,6,7,0,1,2},{11,13,15,17}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << findMin(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int findMin(vector<int> numsVar)
{
    sort(numsVar.begin(), numsVar.end());
    return numsVar[0];
}

void reset () {
  printf("\033[1;0m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void red () {
  printf("\033[1;31m");
}