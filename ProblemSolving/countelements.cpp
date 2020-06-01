//
//  countelements.cpp
//  	
//
//  Created by Yash Arora on 07/04/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int countElements(vector<int>& arr) {
    multiset<int> mymap;
    int count=0;
    int len = arr.size();
    for(int i=0;i<len;i++)
    {
        mymap.insert(arr[i]);
    }
    
    for(int i=0;i<len;i++)
    {
        auto it = mymap.find(abs(arr[i]+1));
        if(it != mymap.end())
            count++;
        
    }
    
    
    return count;
}

int main3(int argc, const char * argv[]) {
    vector<int> arr {1,3,2,3,5,0};
    cout<<countElements(arr)<<endl;
    return 0;
}
