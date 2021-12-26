/*
Name: Gareth Warren
Date: 11/13/21
Class: CIT-145 Z01
IDE: Visual Studio 2022 Community Preview

Chapter 11:
Program that manages a hardware inventory, which creates and reads a file called hardware.dat
containing up to 100 records of various tool items.

User can input new tools, update existing tools, delete tools and view the inventory
*/

#pragma warning(disable: 4996)
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

struct inventoryItem{
    int recordNumber = 0;
    char toolName[80]={'\0'};
    double cost = 0;
    int quantity = 0;
} basicItem;

struct inventoryItem Inventory[100];

//Get Tool Number
int GetToolNum() {
    char toolNum[10];
    int toolNumber;
    int count = 0;
    char* tool;

    tool = fgets(toolNum, 9, stdin);

    if (*tool != NULL) {
        for (int index = 0; index < strlen(toolNum); index++) {
            if (toolNum[index] != NULL && isdigit(toolNum[index])) {
                count++;
            }
        }
        if (count != 0) {
            toolNumber = atoi(toolNum);
            if (toolNumber != 0) {
                return toolNumber;
            }
        }
    }
    return -1;
}

//Assign Data
void AssignData(int toolNumber) {
    char quant[20] = {'\0'};
    char cost[20] = {'\0'};
    char name[80] ={'\0'};
    char* data;

    //Check name is not null
    Inventory[toolNumber - 1].recordNumber = toolNumber;
    printf("Name of Tool:");
    data = fgets(name, 80, stdin);
    if (*data != NULL && name[0] != '\0' && name[0] != '\n') {
        int len = strlen(name);
        //remove newlines
        if (len > 0 && name[len - 1] == '\n') {
            name[len - 1] = '\0';
        }
    }
    else {
        printf("Wrong Format\n");
        return;
    }

    //Check Quantity not null and is number
    printf("\nQuantity: ");
    data = fgets(quant, 19, stdin);
    if (*data != NULL && quant[0] != '\0') {
        int count = 0;
        for (int index = 0; index < strlen(quant); index++) {
            if (quant[index] != NULL && isdigit(quant[index])) {
                count++;
            }
        }
        if (count == 0) {
            printf("Wrong Format\n");
            return;
        }
    }
    
    //Check cost is not null and is number, and may have a '.' 2 spaces from end
    printf("\nCost: ");
    data = fgets(cost, 19, stdin);
    if (*data != NULL && cost[0] != '\0') {
        int count = 0;
        for (int index = 0; index < strlen(cost); index++) {
            if (cost[index] != NULL && (isdigit(cost[index]) || cost[strlen(cost)-2] == '.')) {
                count++;
            }
        }
        if (count == 0) {
            printf("Wrong Format\n");
            return;
        }
    }
    //Assign values if validation passes
    strcpy(Inventory[toolNumber - 1].toolName, name);
    Inventory[toolNumber - 1].quantity = atoi(quant);
    Inventory[toolNumber - 1].cost = atof(cost);
}

//Initialize Function
void InitInventory() {
    for (int index = 0; index < 100; index++) {
        Inventory[index].recordNumber = basicItem.recordNumber;
        strcpy(Inventory[index].toolName, basicItem.toolName);
        Inventory[index].quantity = basicItem.quantity;
        Inventory[index].cost = basicItem.cost;
    }
}

//Write Function
void WriteInventory() {
    printf("Write function executed\n");
    FILE* inventoryFile;
    if (fopen("hardware.dat", "a+") == NULL) {
        printf("An error occurred.");
        return;
    }
    else {
        inventoryFile = fopen("hardware.dat", "w+");
        fwrite(&Inventory, sizeof(struct inventoryItem), 100, inventoryFile);
    }
    fclose(inventoryFile);
}

//Read Function
void ReadInventory() {
    printf("Read function executed\n");
    FILE* inventoryFile;
    if (fopen("hardware.dat", "a+") == NULL) {
        printf("An error occurred.");
        return;
    }
    else {
        inventoryFile = fopen("hardware.dat", "w+");
        fread(&Inventory, sizeof(struct inventoryItem), 100, inventoryFile);
    }
    fclose(inventoryFile);
}

//Create Record
void CreateRecord(){
    bool goAgain = true;
    int toolNumber;
    int selection;
    char placeholder[20];
    char toolNum[10];
    char quant[20];
    char cost[20];
    char name[80];

    printf("File will be written after you are done entering your items.\n");

    do{
        printf("Tool Number (number between 1 and 100): \n");
       
        toolNumber = GetToolNum();

        if (toolNumber <= 100 && toolNumber >= 1) {
            AssignData(toolNumber);
        }
        else {
            printf("Invalid entry\n");
        }
        printf("Do you want to enter another tool? 1-Yes, 2- No: ");
        fgets(placeholder, 7, stdin);
        printf("\n");
        if (isdigit(placeholder[0])) {
            selection = atoi(placeholder);
            if (selection != 1) {
                goAgain = false;
            }
        }
        else {
            goAgain = false;
        }
    } while (goAgain);
}

//Update Record
void UpdateRecord(){
    int toolNumber;
    char toolNum[10];
    char quant[20];
    char cost[20];
    char name[80];
    
    printf("Enter Tool Number to Update: \n");
    
    toolNumber = GetToolNum();

    if (toolNumber <= 100 && toolNumber >= 1) {
        const struct inventoryItem* item = &Inventory[toolNumber - 1];
        printf("Current Entry:\n");
        printf("Tool Name %s\n", (*item).toolName);
        printf("Quantity: %i\n", (*item).quantity);
        printf("Cost: $%.2f\n", (*item).cost);

        AssignData(toolNumber);

        WriteInventory();
    }
    else {
        printf("Invalid entry\n");
    }
}

//Delete Record: Delete Record actually rewrites the entire contents of the file with record omitted
void DeleteRecord(){
    int toolNumber;
    char toolNum[10];
    
    printf("Enter Tool Number to Delete: \n");
    printf("WARNING: This will decrease the existing tool numbers by 1 of all listings after the deleted tool!\n");
    fgets(toolNum, 7, stdin);
    toolNumber = atoi(toolNum);

    if (toolNumber <= 100 && toolNumber >= 1) {
        Inventory[toolNumber - 1] = basicItem;
        struct inventoryItem newInventory[100];
        int newIndex = 0;
        for (int index = 0; index < 100; index++) {
            if (Inventory[index].recordNumber != 0) {
                strcpy(newInventory[newIndex].toolName, Inventory[index].toolName);
                newInventory[newIndex].quantity = Inventory[index].quantity;
                newInventory[newIndex].cost = Inventory[index].cost;
                if (Inventory[index].recordNumber > (newIndex + 1)) {
                    newInventory[newIndex].recordNumber = newIndex + 1;
                }
                else {
                    newInventory[newIndex].recordNumber = Inventory[index].recordNumber;
                }
                newIndex++;
            }
        }
        //Clear Inventory for Rewrite
        InitInventory();

        //Copy Values back to Inventory
        for (int index = 0; index < 100; index++) {
            Inventory[index].recordNumber = newInventory[index].recordNumber;
            strcpy(Inventory[index].toolName, newInventory[index].toolName);
            Inventory[index].quantity = newInventory[index].quantity;
            Inventory[index].cost = newInventory[index].cost;
        }
        WriteInventory();
        printf("Tool Number %i Deleted.\n", toolNumber);
        }
    else {
        printf("Invalid entry\n");
    }
} 
//Read Function
void ListTools(){
    FILE* inventoryFile;
    bool readFile = true;
    struct inventoryItem item;
    struct inventoryItem* theItem = &item;
    if(fopen("hardware.dat", "r+") == NULL){
        printf("An error occurred.\n");
        return;
    }else{
        inventoryFile = fopen("hardware.dat", "r+");
        rewind(inventoryFile);
        printf("List of Tools:\n\n");
        while(readFile){
            if (!feof(inventoryFile)) {
                fread(theItem, sizeof(struct inventoryItem), 1, inventoryFile);
                if ((*theItem).recordNumber != 0) {
                    printf("Tool Number: %i\n", item.recordNumber);
                    printf("Name: %s\n", item.toolName);
                    printf("Quantity: %i\n", item.quantity);
                    printf("Cost: $%.2f\n\n\n", item.cost);
                }
            }
            else { 
                readFile = false; 
            }
        }
    }
    fclose(inventoryFile);
}
//May have to open/close in Main
int main(){
    bool goAgain = true;
    int selection = 0;
    char select[20] = { '\0' };

    InitInventory();
  
    do {
        printf("Enter a Request:\n");
        printf("1: Input a Tool\n");
        printf("2: Update an Existing Tool\n");
        printf("3: Delete a Tool\n");
        printf("4: List all Tools\n");
        printf("5: Exit\n");

        fgets(select, 7, stdin);
        
        if (isdigit(select[0])) {
            selection = atoi(select);

            switch (selection)
            {
            case 1:
                //Create New Records
                goAgain = true;
                printf("Enter Tool Number (between 1 and 100), Name, Quantity and Cost\n");
                CreateRecord();
                WriteInventory();
                break;
            case 2:
                //Update Existing Records
                goAgain = true;
                printf("Enter Tool Number (between 1 and 100), Name, Quantity and Cost\n");
                UpdateRecord();
                break;
            case 3:
                //Delete and Overwrite
                goAgain = true;
                printf("Enter the number of the Tool to be deleted:\n");
                DeleteRecord();
                break;
            case 4:
                //List Inventory
                goAgain = true;
                printf("List All the Tools:\n");
                ListTools();
                break;
            default:
                goAgain = false;
                printf("Exiting Program...\n");
                break;
            }
        }else{
            printf("Try Again\n");
            break;
        }
    }while(goAgain);

    system("pause");
    return 0;
}