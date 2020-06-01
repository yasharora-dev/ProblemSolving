//
//  rotatedarray.cpp
//  	
//
//  Created by Yash Arora on 30/04/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int search(vector<int>& nums, int target) {
    int len = nums.size();
    int low = 0;
    int high = len-1;
    int mid;
    while(low<=high && low >=0 && high < len)
    {
        mid = (low + high)/2;
        
        // mid is key
        if(nums[mid] == target)
            return mid;
        //left half sorted and its on left side
        else if(nums[low] < nums[mid-1] && mid > 0)
        {
            if(target < nums[mid] && target >= nums[low])
                high = mid-1;
            else
                low = mid +1;
        }
        else
        {
            if(target <= nums[high] && target > nums[mid])
                low = mid+1;
            else
                high = mid-1;
        }
        
    }
	    return -1;
}

int rangeBitwiseAnd(int m, int n) {
    int ans=0;
    for(int i=m;i<=n;i++)
    {
        ans=ans&i;
    }
    return ans;
}
int main13()
{
    cout<<rangeBitwiseAnd(5,7)<<endl;
    vector<int> nums {1,3};
    cout<<search(nums,0)<<endl;
    return 0;
}
