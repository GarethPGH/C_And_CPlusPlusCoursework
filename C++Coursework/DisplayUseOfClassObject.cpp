/*
Name: Gareth Warren
Date: 9/22/2121
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Program that creates three player objects and displays them using the class player
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include <iostream>

using namespace std;

class player{
    private: 
        const int MAX_INT = 2147483647;
        //Fields
        string playerName = "";
        string playerPassword = "";
        int playerExperience = 0;
        int playerPosX = 0;
        int playerPosY = 0;
        string playerInventory[4];

    public: 
    //Constructors
    player(){
        string name = "Newbie";
        string password = "Password";
        string item1 = "beginner";
        string item2 = "stuff";
        string item3 = "goes";
        string item4 = "here";
        this-> playerName = name;
        this-> playerPassword = password;
        this-> playerExperience = 0;
        this-> playerPosX = 0;
        this-> playerPosY = 0;
        this-> setInventory(item1, item2, item3, item4);
    }

    player(string name, string password, int experience, int posX, int posY, string item1, string item2, string item3, string item4){
        this-> setName(name);
        this-> setPassword(password);
        this-> setExperience(experience);
        this-> setXPosition(posX);
        this-> setYPosition(posY);
        this-> setInventory(item1, item2, item3, item4);
    }
    //Accessors
    std::string getName(){
        return this-> playerName;
    }

    std::string getPassword(){
        return this-> playerPassword;
    }

    int getExperience(){
        return this-> playerExperience;
    }

    int getXPosition(){
        return this-> playerPosX;
    }

    int getYPosition(){
        return this-> playerPosY;
    }

    string* getInventory(){
    return playerInventory;
}

    //Mutators
    void setName(string name){
        playerName = name;
    }

    void setPassword(string password){
        playerPassword = password;
    }

    void setExperience(int experience){
        if(experience <= MAX_INT && experience >= 0){
            playerExperience = experience;
        }else{
            playerExperience = -1;
        }
    }

    void setXPosition(int position){
        if(position <= MAX_INT && position >= 0){
            playerPosX = position;
        }else{
            playerPosX = -1;
        }
    }

    void setYPosition(int position){
        if(position <= MAX_INT && position >= 0){
            playerPosY = position;
        }else{
            playerPosY = -1;
        }
    }
   //Rewrite using pointer to player inventory
    void setInventory(string item1, string item2, string item3, string item4){
       string* inventory = getInventory();
       inventory[0] = item1;
       inventory[1] = item2;
       inventory[2] = item3;
       inventory[3] = item4;
    }

    void display();
};

void player::display(){
    string* inventory = player::getInventory();
    cout << "Player Name: " << player::getName() << endl;
    cout << "Password: " << player::getPassword() << endl;
    cout << "Experience: " << player::getExperience() << endl;
    cout << "Position: " << player::getXPosition() << " " << player::getYPosition() << endl;
    cout << "Inventory: " << inventory[0]  << ", " << inventory[1] << ", " << inventory[2] << ", " << inventory[3] << endl;
    cout << endl;
}

int main(){
    player player1 {"Bob", "2wdf34rsdf3", 10, 297, 765, "Sword", "Torch", "Rope", "Bedroll"};
    player player2 {"Gorgoth the Great", "IAmAMighty0rkL0rd", 324252, 890, 234, "Morningstar", "Tower Shield","Armor", "Health Potions"};
    player player3 {"Sylvan", "43gf43d", 43523, 8963, 1233, "Longbow", "Quiver and Arrows", "Mana Potions", "Mystical Runes"};

    player1.display();
    player2.display();
    player3.display();

system("pause");
return 0;
}