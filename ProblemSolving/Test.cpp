//
//  Test.cpp
//  	
//
//  Created by Yash Arora on 03/05/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


int solution(vector<int> &A) {
    int N = A.size();
    int result = 0;
    // for (int i = 0; i < N; i++)
    //     for (int j = i; j < N; j++)
    //         if (A[i] != A[j])
    //             result = max(result, j - i);
    
    int low =0;
    int high = N-1;
    
    while(low<high)
    {
        if(A[low]!=A[high])
            result = max(result,high -1);
        low++;
        high--;
            
    }
    return result;
}

int main()
{
    
    vector<int> nums {4, 6, 2, 2, 6, 6, 4};
    cout<<solution(nums)<<endl;
    return 0;
}

