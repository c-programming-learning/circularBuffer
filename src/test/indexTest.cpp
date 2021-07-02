#include <gtest/gtest.h>
#include "../circularBuffer/circularbuffer.h"

/*
 * Input data for writing to circular buffer.
 */
u_int8_t inputData [] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

u_int8_t readbuff[20];

u_int8_t readLen = 0;

/*
 * Test for writing data to the buffer and verifying the index of the buffer.
 *
 */
TEST(consectiveReadWriteTest, WriteReadTest) {
	CicularBufferContext context;
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(5, getcurrWriteIndex(&context));
	EXPECT_EQ(100,getTotalDataLength(&context));

	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(1, getcurrWriteIndex(&context));
	EXPECT_EQ(100,getTotalDataLength(&context));

	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(5, getcurrReadIndex(&context));
	EXPECT_EQ(0,getTotalDataLength(&context));

	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(1, getcurrReadIndex(&context));

	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(2, getcurrReadIndex(&context));

	clearCircularBuffer(&context);
	EXPECT_EQ(0, getcurrReadIndex(&context));


}

/*
 *  Test for write index and the read index of the buffer to verify the indexes.
 */
TEST(readWriteIndexTest, indexTest) {
	CicularBufferContext context;
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(4, getcurrWriteIndex(&context));

	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(1, getcurrReadIndex(&context));
	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(2, getcurrReadIndex(&context));
	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(3, getcurrReadIndex(&context));

	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(5, getcurrWriteIndex(&context));

	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(1, getcurrWriteIndex(&context));

	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(2, getcurrWriteIndex(&context));

	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(3, getcurrWriteIndex(&context));

	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, inputData, 20));
	EXPECT_EQ(4, getcurrWriteIndex(&context));

	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(4, getcurrReadIndex(&context));

	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(5, getcurrReadIndex(&context));

	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(1, getcurrReadIndex(&context));

	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(2, getcurrReadIndex(&context));

	EXPECT_EQ(readbuff, popFromCircularBuffer(&context, readbuff, &readLen));
	EXPECT_EQ(3, getcurrReadIndex(&context));

	clearCircularBuffer(&context);
	EXPECT_EQ(0, getcurrReadIndex(&context));

}
