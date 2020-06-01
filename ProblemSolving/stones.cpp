//
//  stones.cpp
//  	
//
//  Created by Yash Arora on 12/04/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;


int lastStoneWeight(vector<int>& stones) {
    int len = stones.size();
    int ans;
    
    multiset<int,std::greater<int>> mySet;
    
    for(int i:stones)
        mySet.insert(i);
    
    while(mySet.size()>1)
    {
        auto it1 = mySet.begin();
        auto it2 = it1++;
        int newWeight = abs(*it1 - *it2);
        mySet.erase(it1);
        mySet.erase(it2);
        if(newWeight > 0)
            mySet.insert(newWeight);
    }
    
    ans = *(mySet.begin());
    
    return ans;
}


int main7(int argc, const char * argv[]) {
    vector<int> weights {2,7,4,1,8,1};
    cout<<lastStoneWeight(weights)<<endl;
    return 0;
}
