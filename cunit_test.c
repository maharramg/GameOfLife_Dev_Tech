#include <stdio.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>
#include "./game/game.h"

// zero array structure for testing purpose
struct ArrStructZero
{
    int zeroZone[row][column];
};

struct ArrStruct arrayTest;
struct ArrStructZero arrayZero;

void is_filled(void)
{
    arrayTest = fillRandArray(arrayTest);

    printf("\nPlayZone after filling randomly:\n");
    printArray(arrayTest.playZone);

    CU_ASSERT_NOT_EQUAL(arrayTest.playZone, arrayZero.zeroZone);
}

void is_making_copy(void)
{
    arrayTest = makeCopy(arrayTest, arrayTest);

    printf("\nPlayZone:\n");
    printArray(arrayTest.playZone);
    printf("\nPlayZoneCopy after copying:\n");
    printArray(arrayTest.playZoneCopy);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            CU_ASSERT_EQUAL(arrayTest.playZoneCopy[i][j], arrayTest.playZone[i][j]);
        }
    }
}

void is_compared_correct(void)
{
    struct ArrStruct arrayTest1 = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    printf("\nPlayZone:\n");
    printArray(arrayTest1.playZone);
    printf("\nPlayZoneCopy:\n");
    printArray(arrayTest1.playZoneCopy);

    CU_ASSERT_TRUE(compareArray(arrayTest1, arrayTest1));
}

void is_checking_for_not_exist(void)
{
    CU_ASSERT_FALSE(checkForNotExist(arrayTest));
}

void is_counting_neighbours_clipped(void)
{
    struct ArrStruct arrTestBefore = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    struct ArrStruct arrTestAfter = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    printf("\nCurrent generation:\n");
    printArray(arrTestBefore.playZone);

    arrTestBefore = countNeighboursClipped(arrTestBefore);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            CU_ASSERT_EQUAL(arrTestBefore.playZone[i][j], arrTestAfter.playZone[i][j]);
        }
    }

    printf("\nNext generation:\n");
    printArray(arrTestAfter.playZone);
}

void is_counting_neighbours_circular(void)
{
    struct ArrStruct arrTestBefore = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    struct ArrStruct arrTestAfter = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    printf("\nCurrent generation:\n");
    printArray(arrTestBefore.playZone);

    arrTestBefore = countNeighboursCircular(arrTestBefore);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            CU_ASSERT_EQUAL(arrTestBefore.playZone[i][j], arrTestAfter.playZone[i][j]);
        }
    }
    printf("\nNext generation:\n");
    printArray(arrTestBefore.playZone);
}

int main()
{
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    CU_pSuite pSuite1 = CU_add_suite("Testing random filling of array", NULL, NULL);
    CU_ADD_TEST(pSuite1, is_filled);

    CU_pSuite pSuite2 = CU_add_suite("Testing making copy of arrays", NULL, NULL);
    CU_ADD_TEST(pSuite2, is_making_copy);

    CU_pSuite pSuite3 = CU_add_suite("Testing comparing of arrays", NULL, NULL);
    CU_ADD_TEST(pSuite3, is_compared_correct);

    CU_pSuite pSuite4 = CU_add_suite("Testing existence of cells in arrays", NULL, NULL);
    CU_ADD_TEST(pSuite4, is_checking_for_not_exist);

    CU_pSuite pSuite5 = CU_add_suite("Testing counting neighbours clipped", NULL, NULL);
    CU_ADD_TEST(pSuite5, is_counting_neighbours_clipped);

    CU_pSuite pSuite6 = CU_add_suite("Testing counting neighbours circular", NULL, NULL);
    CU_ADD_TEST(pSuite6, is_counting_neighbours_circular);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    return CU_get_number_of_failures();
}