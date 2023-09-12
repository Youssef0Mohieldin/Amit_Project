#ifndef _SDB_H_
#define _SDB_H_
#include "STD.h"
typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
} students;

bool SDB_IsFull(); // done

uint8 SDB_GetUsedSize(); // done

bool SDB_AddEntry(); // done

void SDB_DeletEntry(uint32 id); // done

bool SDB_ReadEntry(uint32 id); // done

void SDB_GetList(uint8 *count, uint32 *list); // done

bool SDB_IsIdExist(uint32 id); // done

void SDB_APP();

void SDB_action(uint8 choice);

#endif
