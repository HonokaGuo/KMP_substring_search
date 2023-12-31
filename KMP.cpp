#include <iostream>
#include <String>
using namespace::std;
//return a index, -1 if not found
int KMP (string& superString, string& pattern, int start = 0); 
int main(void) {
    string a = "abxabyabzabfabzabg";         //abxabcabcaby
    string b = "abz";         //abcaby

    cout << KMP(a, b, 7) << endl;
    return 0;
}

int KMP (string& superString, string& pattern, int start) {
    int supSize = superString.size();
    int patSize = pattern.size();                               
    int *sup = new int[supSize], *pat = new int[patSize];
    if (patSize < 2) {                                  
        for (int i = 0; i < supSize; ++i) {
            if (pattern[0] == superString[i]) {         //pattern is a single character
                return i;
            }
        }     
        return -1;       
    }

    int i{0}, j{1};
    pat[i] = 0;
    while (i < patSize && j < patSize) {
        if (pattern[i] != pattern[j]) {
            if (i != 0) {
                i = pat[i - 1];
            } else {
                pat[j] = 0;
                ++j;
                continue;
            }
            
            while (i > 0 && pattern[i] != pattern[j]) {
                i = pat[i - 1];
            }
            if (i == 0) {
                pat[j] = 0;
            } else {
                pat[j] = i + 1;
            }
            
            ++j;  
        } else {
            pat[j] = i + 1;
            ++i;
            ++j;
        }

     
    }
    
    
       /*for (i = 0; i < patSize; ++i) {
            cout << pat[i] << endl;
        }
        return 0;   */ 
    //so far pat[] has successfully intialized !!
    
    for (i = start, j = 0; i < supSize && j < patSize;) {
        
        if (superString[i] == pattern[j]) {
            ++j;
            ++i;
        } else if (j != 0) {
            j = pat[j - 1];
        } else {
            ++i;
        }
    }

        
       if (j == patSize) {
            return i - patSize;
        }
    
    
    delete sup;
    delete pat;
    return -1;
}