//
//  stringequal.cpp
//  	
//
//  Created by Yash Arora on 09/04/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;


  bool backspaceCompare(string S, string T) {
      int len1 = S.length();
      int len2 = T.length();

      int i = len1-1; int skipS=0;
      int j = len2-1; int skipT=0;
      while(i >=0 && j >=0)
      {
         while(i>=0)
         {
             if(S[i] == '#')
             {
                 skipS++;
                 i--;
             }
             else if(skipS > 0)
             {
                 i--;
                 skipS--;
             }
             else
                 break;
         }
          
          while(j>=0)
          {
              if(T[j] == '#')
              {
                  skipT++;
                  j--;
              }
              else if(skipT > 0)
              {
                  j--;
                  skipT--;
              }
              else
                  break;
          }
          
          if(i>=0 && j>=0 && S[i]!=T[j])
              return false;
          
          if((i>=0)!=(j>=0))
              return false;
          
          i--;
          j--;
          
      }
      
      return true;
      
  }
int main6(int argc, const char * argv[]) {
    //string S="ab##";
    //string T="c#d#";
    string S="a##c";
    
    string T ="#a#c";
    //string T="xywrrmu#p";
    cout<<backspaceCompare(S, T)<<endl;
    return 0;
}
