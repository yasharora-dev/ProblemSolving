//
//  stack.cpp
//  	
//
//  Created by Yash Arora on 12/04/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack {
    stack<int> _stack; //original stack
    int min; //contains min element at top
public:
    /** initialize your data structure here. */
    MinStack() {
        min=INT_MAX;
    }
    
    void push(int x) {
        if(_stack.empty())
        {
            _stack.push(x);
            min=x;
            return;
        }
        if(x < min)
        {
            
            //_stack.push(2*x-min);
           

            if( (x >= 0 && min >= 0 ) )
            {
                
                _stack.push(x - min);
                min = x;
            }
            else
            {
                
                _stack.push(x + min);
                min = x;
            
            }
            
        }
        else
            _stack.push(x);
        
        
    }
    
    void pop() {
        if(_stack.empty())
            return;
        int topEle = _stack.top();
        if(topEle <= min)
        {
            //min = 2*min - topEle;
            if(min == 0)
                min = abs(topEle);
            else if((min < 0 && topEle < 0) || (topEle > 0 && min >0) )
                min = topEle-min;
            else
                min = topEle+min;
        }
        
        _stack.pop();
    }
    
    int top() {
        int topEle = _stack.top();
        if(topEle < min)
            return min;
        else
            return topEle;
        
    }
    
    int getMin() {
        return min;
    }
};
int main8(int argc, const char * argv[]) {
   
    MinStack minStack;
    minStack.push(512);
    minStack.push(-1024);
    minStack.push(-1024);
    minStack.push(512);
     // --> Returns -3.
    minStack.pop();
    int p2 = minStack.getMin(); //
    minStack.pop();
    int p3 = minStack.getMin();  // --> Returns -2.
    minStack.pop();
    int p4 = minStack.getMin();
    
    return 0;
}

