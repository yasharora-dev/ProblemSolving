//
//  anagram.cpp
//  	
//
//  Created by Yash Arora on 06/04/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
using namespace std;

int getASCIISum(string& str)
{
    int len = str.length();
    int sum=0;
    for(int i=0;i<len;i++)
    {
        sum= sum + (str[i]-'a') + 1;
    }
    return sum;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    //key = ascii sum and index = index of result array
    map<int,int> indexTable;
    int len = strs.size();
    int index =0;
    for(int i=0;i<len;i++)
    {
        int sum = getASCIISum(strs[i]);
        auto it = indexTable.find(sum);
        
        if(it == indexTable.end())
        {
            indexTable[sum]=index;
            vector<string> s;
            s.push_back(strs[i]);
            ans.push_back(s);
            index++;
        }
        else
        {
            ans[it->second].push_back(strs[i]);
        }
    }
    
    return ans;
}


int main2(int argc, const char * argv[]) {
    //vector<string> input {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> input {"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};
    vector<vector<string>> ans = groupAnagrams(input);
  
    return 0;
}
