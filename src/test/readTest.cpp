
#include <gtest/gtest.h>
#include "../circularBuffer/circularbuffer.h"

/*
 * The input test data for the testing circular buffer.
 */
u_int8_t testData1 [] = {1,2,3,4,5,6,7,8,9,40,11,82,23,14,15,16,17,76,19,20};
u_int8_t testData2 [] = {1,2,23,4,5,6,7,15,9,10};
u_int8_t testData3 [] = {11,25,3,4,54,6,7,83,9};
u_int8_t zeroData [] = {0};
/*
 * The array for getting the data read from the circular buffer .
 */
u_int8_t readDataBuff [20];
u_int8_t readDataAfterClear [20];
u_int8_t readDataLen;
/*
 *  Test for verifying the written data and the length of the data.
 */
TEST(compareDataAndLengthTest, DataCompareTest) {
	CicularBufferContext context;
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, testData1, sizeof(testData1)));
	EXPECT_EQ(0, memcmp(testData1, popFromCircularBuffer(&context,readDataBuff, &readDataLen), sizeof(testData1)));
	EXPECT_EQ(sizeof(testData1),readDataLen);

	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context,testData2, sizeof(testData2)));
	EXPECT_EQ(0, memcmp(testData2, popFromCircularBuffer(&context,readDataBuff, &readDataLen), sizeof(testData2)));
	EXPECT_EQ(sizeof(testData2),readDataLen);

	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context,testData3, sizeof(testData3)));
	EXPECT_EQ(0, memcmp(testData3, popFromCircularBuffer(&context,readDataBuff, &readDataLen), sizeof(testData3)));
	EXPECT_EQ(sizeof(testData3),readDataLen);

	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, testData1, sizeof(testData1)));
	clearCircularBuffer(&context);
	EXPECT_EQ(0,memcmp(popFromCircularBuffer(&context,readDataAfterClear, &readDataLen), zeroData, sizeof(testData3)) );
	EXPECT_EQ(0,readDataLen);
	EXPECT_EQ(0,getTotalDataLength(&context));

}
