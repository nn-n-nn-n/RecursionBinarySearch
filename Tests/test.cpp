#include "pch.h"
#include "Task.h"
#include <iostream>
using namespace std;
using namespace std;

TEST(TestTask, ZeroArray) {

	int m[] = { 1 };
	int size = 0;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, 1), -1));

}

TEST(TestTask, ArrayWith1Element) {

	int m[] = { 1 };
	int size = sizeof(m)/sizeof(int);
	int value = 1;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 0));
	value = 2;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), -1));
}


TEST(TestTask, ArrayWith2Element) {

	int m[] = { 1, 2 };
	int size = sizeof(m) / sizeof(int);
	int value = 2;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 1));
	value = 1;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 0));
	value = 3;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), -1));
}

TEST(TestTask, ArrayWith3Element) {

	int m[] = { 1, 2, 3 };
	int size = sizeof(m) / sizeof(int);
	int value = 2;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 1));
	value = 1;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 0));
	value = 3;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 2));
	value = -1;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), -1));
}

TEST(TestTask, ArrayWithOddElementsCount) {

	int m[] = { 1, 2, 3,4,5,6,7,8,9 };
	int size = sizeof(m) / sizeof(int);
	int value = 9;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 8));
	value = 1;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 0));
	value = 3;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 2));
	value = 10;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), -1));
}

TEST(TestTask, ArrayWithEvenElementsCount) {

	int m[] = { 1, 2, 3,4,5,6,7,8,9, 10 };
	int size = sizeof(m) / sizeof(int);
	int value = 9;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 8));
	value = 1;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 0));
	value = 3;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 2));
	value = 10;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 9));
	value = 0;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), -1));
}

TEST(TestTask, ArrayWithSeveralEqualsElements) {

	int m[] = { 1, 2,2,2,2,2,2,2, 3,4,5,6,7,8,9, 10 };
	int size = sizeof(m) / sizeof(int);
	int value = 2;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 1));
}

TEST(TestTask, ArrayWithSeveralEqualsElementsInTheMiddle) {

	int m[] = { 1, 2,2,2,2,2,2,2, 3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,5,6,7,8,9, 10 };
	int size = sizeof(m) / sizeof(int);
	int value = 3;
	EXPECT_NO_THROW(EXPECT_EQ(RecursionBinarySearch(m, size, value), 8));
}