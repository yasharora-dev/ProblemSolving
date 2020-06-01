//
//  main.cpp
//  yhj
//
//  Created by Yash Arora on 02/04/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

    int SquareNumber(int n)
    {
        string s = std::to_string(n);
        int num = (s[0] - '0') * (s[0] - '0');
        for(int i=1;i<s.size();i++)
        {
            num+= (s[i] - '0') * (s[i]-'0');
        }
        return num;
    }
    bool isHappy(int n)
    {
        set<int> mySet;
        
        while(true)
        {
            int num = SquareNumber(n);
            if(num==1)
                return true;
            else if(mySet.find(num)== mySet.end())
            {
                mySet.insert(num);
                n = num;
            }
            else
                return false; //as the same number started repeating and it will lead to infinite loop

        }
    }

int maxProfit(vector<int>& prices) {
    int len = prices.size();
    int max_profit=0;
    
    for(int i=0;i<len;i++)
    {
        int profit=0;
        int max=0;
        for(int j=i+1;j<len;j++)
        {
            int price = prices[j]-prices[i];
            if( price > 0)
            {
                profit +=price;
                if(profit > max_profit)
                    max += profit;
                i=j;
                break;
            }
        }
    }
    return max_profit;
}


int main1(int argc, const char * argv[]) {
    // insert code here...
    //cout<<isHappy(20)<<endl;
    
    vector<int> arr {7,1,5,3,6,4};
    cout<<maxProfit(arr)<<endl;
    
    vector<int> arr1 {1,2,3,4,5};
    cout<<maxProfit(arr1)<<endl;
    
    vector<int> arr2 {7,6,4,3,1};
    cout<<maxProfit(arr2)<<endl;
    
    return 0;
}
