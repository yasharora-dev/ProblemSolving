//
//  linkedlist.cpp
//  	
//
//  Created by Yash Arora on 08/04/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


ListNode* middleNode(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast;
    if(head->next)
        fast=head->next;
    
    while(slow!=NULL && fast && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    if(fast)
        slow=slow->next;
    
    
    return slow;
}

int main4(int argc, const char * argv[]) {
   
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next= new ListNode(6);
    
    ListNode *midNode = middleNode(head);
    
    while(midNode!=NULL)
    {
        cout<<midNode->val<<" : ";
        midNode=midNode->next;
    }
    return 0;
}


