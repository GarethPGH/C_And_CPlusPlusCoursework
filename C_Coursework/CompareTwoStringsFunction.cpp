/*
Name: Gareth Warren
Date: 10/8/21
Class: CIT-145 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

/*Completely describe what the following function does: 
int mystery( const char *s1, const char *s2 ) 
{ 
    for( ; *s1 != '\0' && *s2 != '\0'; s1++, s2++ ) { 
   if( *s1 != *s2 ) { 
      return 0; 
   }//end if 
    }//end for 

    return 1; 
}*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

/*This function compares two c strings, using pointers
If the value of pointer s1 does not match the value of pointer s2,
Return 0 for false, indicating they do not match.
Else return 1 for true, indicating they are the same string.

There is no initialization of the for loop because the control is done through
moving the pointer along the char values in the c string.
The comparison indicates that both pointer s1 and pointer s2 
must reach the null terminator at the same time.
Otherwise the loop continues, and will return false at the next iteration
or crash by accessing an index out of scope for the provided pointer 
ie: that two strings of different lengths could crash the provided function

Testing reveals that the function works. 
With strings that are similar, but one is longer, the function returns 0 for true.
This is an error. The developer must be wary of testing for length prior to passing strings.

I do not know if the function will work the same on other compilers.

It is far clearer to write something like this:
*/

int CompareTwoCStrings( const char *cstring1, const char *cstring2 ) 
{ 
    for( ; *cstring1 != '\0' && *cstring2 != '\0'; cstring1++, cstring2++ ) { 
        if( *cstring1 != *cstring2 ) { 
            return 0; 
        }//end if 
    }//end for 

    return 1; 
}

void CheckCStrings(int isTrueOrFalse){
    if(isTrueOrFalse == 1){
        printf("The strings match!\n");
    }else if(isTrueOrFalse == 0){
        printf("The strings are not the same\n");
    }else{
        printf("Something weird happened! Exiting program\n");
        exit(1);
    }
}

int main(){
    char cstring1[] = "I'm a string!";
    char cstring2[] = "I'm a string!";
    char cstring3[] = "I'm not the same string as the other strings";
    char cstring4[] = "I'm a string! but longer than the other two strings";
     
    //Test two strings that are the same 
    int checkMe = CompareTwoCStrings(cstring1, cstring2);
    CheckCStrings(checkMe);
    //Test two strings that are not the same.
    checkMe = CompareTwoCStrings(cstring1, cstring3);
    CheckCStrings(checkMe);
    //Test two strings that are similar but one is longer.
    checkMe = CompareTwoCStrings(cstring1, cstring4);
    CheckCStrings(checkMe);

    system("pause");
    return 0;
}
