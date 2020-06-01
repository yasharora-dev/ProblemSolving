#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to find maximum length sub-array having equal number
// of 0's and 1's
int max_len_subarray(vector<int> arr)
{
    int n = arr.size();
    // create an empty map to store ending index of first sub-array
    // having some sum
    unordered_map<int, int> map;

    // insert (0, -1) pair into the set to handle the case when
    // sub-array with sum 0 starts from index 0
    map[0] = -1;

    // len stores the maximum length of sub-array with sum 0
    int len = 0;

    // stores ending index of maximum length sub-array having sum 0
    int ending_index = -1;

    int sum = 0;

    // Traverse through the given array
    for (int i = 0; i < n; i++)
    {
        // sum of elements so far (replace 0 with -1)
        sum += (arr[i] == 0)? -1 : 1;

        // if sum is seen before
        if (map.find(sum) != map.end())
        {
            // update length and ending index of maximum length
            // sub-array having sum 0
            if (len < i - map[sum])
            {
                len = i - map[sum];
                ending_index = i;
            }
        }
        // if sum is seen for first time, insert sum with its
        // index into the map
        else {
            map[sum] = i;
        }
    }

    // print the sub-array if present
    if (ending_index != -1) {
        return ending_index - len + 1 - ending_index ;
    } else {
        return -1;
    }
}

// main function
int main10()
{
    vector<int> arr  { 0, 0, 1, 0, 1, 0, 0 };
   

    cout<< max_len_subarray(arr) <<endl;

    return 0;
}
