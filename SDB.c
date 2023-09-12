#include <stdio.h>
#include <windows.h>
#include "STD.h"
#include "SDB.h"
#define MAX_STUDENTS 10

students student[MAX_STUDENTS];

uint8 current_size = 0;
/*
 * ========= SDB_IsFull() =========
 * @brief: checks if database is full or not
 *
 * @parameters: None
 *
 * @Return value: full:     return -> true
 *                not full: return -> false
 *
 * @functionality: current_size is incremented whenever
 *                 a new student is added, so in case of
 *                 the database being full, current_size
 *                 will have the same value as MAX_STUDENTS
 *                 which is 10, the maximum size of
 *                 the database
 *
 */
bool SDB_IsFull()
{
    if (current_size == MAX_STUDENTS)
        return true;
    else
        return false;
}
/*
 * ========= SDB_GetUsedSize() =========
 * @brief: returns number of students
 *         stored in the database
 *
 * @parameters: None
 *
 * @Return value: full: return -> number of students
 *
 *
 * @functionality: current_size is increamented whenever
 *                 a new srudent is added, if 2 students
 *                 were added, current_size will have the
 *                 value of 2 -> current_size = 2
 *
 */
uint8 SDB_GetUsedSize()
{
    return current_size;
}
/*
 * ========= SDB_AddEntry() =========
 * @brief: stores student information
 *
 * @parameters: None
 *
 * @Return value: success: return -> true
 *                fail:    return -> false
 *
 *
 * @functionality:  -> declaring a struc variable std_data
 *                  -> storing current_student data
 *                     in std_data temporarily
 *                  -> storing data stored
 *                     in std_data in -> student[current_student]
 *                     aka database
 *                  -> if the entered id is already exist
 *                     function will fail -> return false
 *                  -> then increasing current_student by 1
 *                     to indicate that an element is added
 *                     to the database
 *
 */
bool SDB_AddEntry()
{
    if (SDB_IsFull())
    {
        printf("\nDatabase is full!\n\a");
        return false;
    }
    else
    {
        students std_data;
        uint32 id;
        printf("Enter student ID:\t");
        scanf("%u", &id);

        if (SDB_IsIdExist(id))
        {
            printf("\nStudent already exists!\n\a");
            return false;
        }
        else
        {
            std_data.Student_ID = id;
            printf("Enter student Year:\t");
            scanf("%u", &std_data.Student_year);
            printf("Enter Course 1 ID:\t");
            scanf("%u", &std_data.Course1_ID);
            printf("Enter course 1 Grade:\t");
            scanf("%u", &std_data.Course1_grade);
            printf("Enter Course 2 ID:\t");
            scanf("%u", &std_data.Course2_ID);
            printf("Enter course 2 Grade:\t");
            scanf("%u", &std_data.Course2_grade);
            printf("Enter Course 3 ID:\t");
            scanf("%u", &std_data.Course3_ID);
            printf("Enter course 3 Grade:\t");
            scanf("%u", &std_data.Course3_grade);

            student[current_size] = std_data;
            current_size++;
            return true;
        }
    }
}
/*
 * ========= SDB_IsIdExist() =========
 * @brief: stores student information
 *
 * @parameters: student id -> uint32 id
 *
 * @Return value: student found:        return -> true
 *                student not found:    return -> false
 *
 *
 * @functionality: loops the whole students in the database
 *                 if found -> returns true
 *                 if not   -> returns false
 *
 */
bool SDB_IsIdExist(uint32 id)
{
    uint8 counter;
    for (counter = 0; counter < current_size; counter++)
    {
        if (student[counter].Student_ID == id)
        {
            return true;
        }
    }
    return false;
}
/*
 * ========= SDB_ReadEntry() =========
 * @brief: search for a specific student
 *         with ID and print his data
 *
 * @parameters: student id -> uint32 id
 *
 * @Return value: student found:        return -> true
 *                student not found:    return -> false
 *
 *
 * @functionality: loops the whole students in the database
 *                 if found -> print his data then returns true
 *                 if not   -> returns false
 *
 */
bool SDB_ReadEntry(uint32 id)
{
    bool state = SDB_IsIdExist(id);
    if (state == true)
    {
        uint8 counter;
        for (counter = 0; counter < current_size; counter++)
        {
            if (student[counter].Student_ID == id)
            {
                printf("\nPrinting student data......\n");
                Sleep(350);
                printf("student ID: %u \n", student[counter].Student_ID);

                printf("student Year: %u \n", student[counter].Student_year);

                printf("Course 1 ID: %u \n", student[counter].Course1_ID);

                printf("course 1 Grade: %u \n", student[counter].Course1_grade);

                printf("Course 2 ID: %u \n", student[counter].Course2_ID);

                printf("course 2 Grade: %u \n", student[counter].Course2_grade);

                printf("Course 3 ID: %u \n", student[counter].Course3_ID);

                printf("course 3 Grade: %u \n", student[counter].Course3_grade);
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}
/*
 * ========= SDB_DeletEntry() =========
 * @brief: search for a specific student
 *         with ID and delete his data
 *
 * @parameters: student id -> uint32 id
 *
 * @Return value: None
 *
 *
 * @functionality: loops the whole students in the database
 *                 if found -> returns true, then current_size
 *                             is decreamented by 1, and each
 *                             element is transitioned to the
 *                             left to fill the gaps
 *                 if not   -> returns false
 *
 */
void SDB_DeletEntry(uint32 id)
{
    if (SDB_IsIdExist(id))
    {
        uint8 counter;
        for (counter = 0; counter < current_size; counter++)
        {
            if (student[counter].Student_ID == id)
            {
                uint8 inner_counter;
                for (inner_counter = counter; inner_counter < current_size - 1; inner_counter++)
                {
                    student[inner_counter].Student_ID = student[inner_counter + 1].Student_ID;
                }
            }
        }
        printf("\nStudent whose id is: %u is deleted successfully!\n\a", id);
        current_size--;
    }
    else
    {
        printf("\nStudent whose id is: %u doesn't exist!\n\a", id);
    }
}
/*
 * ========= SDB_GetList() =========
 * @brief: This function returns -> pointer to a variable
 *         storing number of IDs, which is also the
 *         size of the database current_size,
 *         and -> a pointer to array storing the IDs
 *
 * @parameters:  count -> returns pointer to variable storing number of IDs
 *               list  -> returns pointer to array storing the IDs
 *
 * @Return value: None
 *
 *
 * @functionality:
 *
 */
void SDB_GetList(uint8 *count, uint32 *list)
{
    *count = current_size;
    uint8 counter;
    for (counter = 0; counter < current_size; counter++)
    {
        *(list + counter) = student[counter].Student_ID;
    }
}
