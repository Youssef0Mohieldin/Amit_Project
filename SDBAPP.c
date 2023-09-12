#include "STD.h"
#include "SDB.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define sleep_duration 1500
#define long_sleep_duration 2000
#define MAX_STUDENTS 10

/*
 * ========= SDB_APP() =========
 * @brief: super loop, at which a specific function
 *         is called based on user entered value (0 - 7)
 *
 * @parameters: None
 *
 * @Return value: None
 *
 *
 * @functionality: it has a super loop it will make your project
 *                 until the user chose to exit you will ask
 *                 the user to choose between these options:
 *                 1)   To add entry, enter 1
 *                 2)   To get used size in database, enter 2
 *                 3)   To read student data, enter 3
 *                 4)   To get the list of all student IDs, enter 4
 *                 5)   To check is ID is existed, enter 5
 *                 6)   To delete student data, enter 6
 *                 7)   To check is database is full, enter 7
 *                 8)   To exit enter 0
 *
 */
void SDB_APP()
{
    uint8 choice = 0;
    while (1)
    {
        printf("1)   To add entry,                       enter -> 1\n");
        printf("2)   To get used size in database,       enter -> 2\n");
        printf("3)   To read student data,               enter -> 3\n");
        printf("4)   To get the list of all student IDs, enter -> 4\n");
        printf("5)   To check is ID is existed,          enter -> 5\n");
        printf("6)   To delete student data,             enter -> 6\n");
        printf("7)   To check is database is full,       enter -> 7\n");
        printf("8)   To exit enter -> 0\n");
        scanf("%u", &choice);
        if (choice == 0)
        {
            break;
        }
        SDB_action(choice);
        system("cls");
    }
}
/*
 * ========= SDB_action() =========
 * @brief: it takes the user choice and call
 *         the responding function for this
 *         choice
 *
 * @parameters: choice
 *
 * @Return value: None
 *
 *
 * @functionality: it takes a user input -> choice
 *                 calls a specific functions corresponding
 *                 to each choice:
 *
 *                 1)   To add entry, enter 1
 *                 2)   To get used size in database, enter 2
 *                 3)   To read student data, enter 3
 *                 4)   To get the list of all student IDs, enter 4
 *                 5)   To check is ID is existed, enter 5
 *                 6)   To delete student data, enter 6
 *                 7)   To check is database is full, enter 7
 *                 8)   To exit enter 0
 *
 */
void SDB_action(uint8 choice)
{
    system("cls");
    uint8 count = 0;
    uint32 list[MAX_STUDENTS] = {0};

    if (choice == 1)
    {
        if (SDB_AddEntry())
        {
            printf("\nEntry added successfully!\a");
            Sleep(sleep_duration);
        }
        else
        {
            printf("\nEntry cann't be added!\a");
            Sleep(sleep_duration);
        }
    }
    else if (choice == 2)
    {
        if (SDB_GetUsedSize() >= 0 && SDB_GetUsedSize() <= MAX_STUDENTS)
        {
            system("cls");
            printf("Used size: %u ", SDB_GetUsedSize());
            Sleep(sleep_duration);
        }
        else
        {
            system("cls");
            printf("Unexpected Error\a"); // unexpected error
            Sleep(sleep_duration);
        }
    }
    else if (choice == 3)
    {
        uint32 id;
        system("cls");
        printf("Enter the id: ");
        scanf("%u", &id);
        if(SDB_ReadEntry(id))
        {
        }else
        {
            printf("Student not found!\a");
        }
        Sleep(sleep_duration);
    }
    else if (choice == 4)
    {
        uint8 counter;
        SDB_GetList(&count, list);
        system("cls");
        if(list[0] == 0)
        {
            printf("data base is empty!\a");
        }else
        {
            printf("Number of IDs: %u\n", count);
            for (counter = 0; counter < count; counter++)
            {
                printf("ID[%u]: %u\n", counter + 1, list[counter]);
            }
        }

        Sleep(long_sleep_duration);
    }
    else if (choice == 5)
    {
        uint32 id;
        system("cls");
        printf("Enter the ID: ");
        scanf("%u", &id);
        if (SDB_IsIdExist(id))
        {
            system("cls");
            printf("ID exists!\a");
            Sleep(sleep_duration);
        }
        else
        {
            printf("\nID not found!\a");
            Sleep(sleep_duration);
        }
    }
    else if (choice == 6)
    {
        system("cls");
        uint32 id;
        printf("Enter ID:\t");
        scanf("%u", &id);
        system("cls");
        SDB_DeletEntry(id);
        Sleep(sleep_duration);
    }
    else if (choice == 7)
    {
        system("cls");
        if (SDB_IsFull())
        {
            printf("Data base is Full\a");
            Sleep(sleep_duration);
        }
        else
        {
            printf("Data base is not Full\a");
            Sleep(sleep_duration);
        }
    }
    else
    {
        system("cls");
        printf("\nIncorrect Option!\a");
        Sleep(sleep_duration);
    }
    system("cls");
}
