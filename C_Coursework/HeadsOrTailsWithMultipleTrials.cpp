/*
Name: Gareth Warren
Date: 9/24/21
Class: CIT-145 Z01
IDE: Visual Studio 2019 Community Edition

HeadsOrTails determines if a virtual coin toss is heads or tails based on a random number between 0 and 1
Then the program runs the simulation for 10, 100, 1000, 10000, 100000, and 1000000 trials.
User has the option to re-run trials. Larger numbers of trials yields closer to a 50/50 result. 
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>

//True = Heads, Tails = False, using a random number between 0 and 1
bool HeadsOrTails(){
    double random = rand()/(double)RAND_MAX;
    if(random > 0.5){
        return true;
    }else{
        return false;
    }
}

int main(){
    //seed rand
    srand(time(NULL));

    const int SIZE = 6;
    const int trials[] = {10, 100, 1000, 10000, 100000, 1000000};
    int headCounter[SIZE];
    int tailCounter[SIZE];
    double headPercentage[SIZE];
    double tailPercentage[SIZE];
    bool coin = false;
    bool goAgain = false;
    int trial = 0;
    int hCount = 0;
    int tCount = 0;
    int selection = 0;
    
    do{
        //Reset loop control
        goAgain = false;
        
        //Calculate the number of heads and tails for each trial, and show a percentage
        for(int index = 0; index < SIZE; index++){
            while(trial <= trials[index]){
                coin = HeadsOrTails();
                if(coin == true){
                    hCount++;
                }else{
                    tCount++;
                }
                trial++;
            }
            headCounter[index] = hCount;
            tailCounter[index] = tCount;
            headPercentage[index] = ((double)hCount/(double)trials[index]) * 100;
            tailPercentage[index] = ((double)tCount/(double)trials[index]) * 100;
            
            printf("Trials: %d\n", trials[index]);
            printf("Head Count: %d , Head Percentage: %.2f\n", headCounter[index], headPercentage[index]);
            printf("Tail Count: %d , Tail Percentage: %.2f\n\n", tailCounter[index], tailPercentage[index]);
        }

        //Ask to rerun simulation
        printf("Do you want to Go Again? 1 = yes, 0 = no: ");
       	if (scanf("%d", &selection)) {
			if (selection == 1) {
				goAgain = true;

                //Reset counter variables
                trial = 0;
                hCount = 0;
                tCount = 0;
        
                //Reset arrays
                for(int index = 0; index < SIZE; index++){
                    headCounter[index] = 0;
                    tailCounter[index] = 0;
                    headPercentage[index] = 0.0;
                    tailPercentage[index] = 0.0;
                }
                //Print new line
                printf("\n");
			}
			else { 
				goAgain = false;
			}
		}else{
            goAgain = false;
        }
    
    }while(goAgain);

    printf("Exiting program.\n");

    system("pause");
    return 0;
}