/*
Name: Gareth Warren
Date: 10/18/2121
Class: CIT-145 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Chapter 8:
Write a program that uses the random number generator to create 20 random sentences
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Generates random number given a specific limit value
int GetRandomNumber(int limit){
    return rand() % limit;
}

//Prints random sentences using a char* pointer that is allocated and freed in each function call
void GenerateRandomSentence(){
    //Construct sentence with article, noun, verb, preposition, article, noun.
    static unsigned int SIZE = 5;
    static unsigned int strSize = 41;
    char* sentence = (char*)malloc(strSize);
    int random = 0;
    const char* article[]= {"the", "one", "a", "some", "any"};
    const char* noun[] ={"boy", "girl", "dog", "town", "car"};
    const char* verb[] ={"drove", "jumped", "walked", "ran", "skipped"};
    const char* preposition[] ={"to", "from", "over", "under", "on"};
      
    strcpy(sentence, "");
    random = GetRandomNumber(SIZE);
    strcat(sentence, article[random]);
    strcat(sentence, " ");
    random = GetRandomNumber(SIZE);
    strcat(sentence, noun[random]);
    strcat(sentence, " ");
    random = GetRandomNumber(SIZE);
    strcat(sentence, verb[random]);
    strcat(sentence, " ");
    random = GetRandomNumber(SIZE);
    strcat(sentence, preposition[random]);
    strcat(sentence, " ");
    random = GetRandomNumber(SIZE);
    strcat(sentence, article[random]);
    strcat(sentence, " ");
    random = GetRandomNumber(SIZE);
    strcat(sentence, noun[random]);

    printf("%s\n", sentence);
    
    free(sentence);
}

int main(){
    srand(time(NULL));

    //Generate 20 Random Sentences from GenerateRandomSentence, and GetRandomNumber
    printf("Here are 20 Random sentences using C string functions, a random number, and 4 char* arrays\n\n");    

    for(int count = 1; count <= 20; count++){
        GenerateRandomSentence();
    }
    system("pause");
    return 0;
}
