#include <gtest/gtest.h>
#include "../circularBuffer/circularbuffer.h"

u_int8_t testData [] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
/**
 * Test case for appending data to circular buffer and testing the buffer write index.
 */
TEST(firstWriteTest, bufferWriteTest) {
	CicularBufferContext context;
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, testData, 20));
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, testData, 20));
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, testData, 20));
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, testData, 20));
	EXPECT_EQ(SUCCESS, appendToCircularBuffer(&context, testData, 20));
	EXPECT_EQ(5, getcurrWriteIndex(&context));
	EXPECT_EQ(100,getTotalDataLength(&context));
	clearCircularBuffer(&context);
	EXPECT_EQ(0, getcurrWriteIndex(&context));
}

