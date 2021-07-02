
#include "circularBuffer.h"
#include <string.h>

#define MAX_NUM_OF_PACKETS 	5
#define LENGTH_OF_PACKET    20

typedef struct{
	u_int8_t length;
	u_int8_t buf[LENGTH_OF_PACKET];
}st_message_buffer;

st_message_buffer buffer[MAX_NUM_OF_PACKETS];

u_int8_t appendToCircularBuffer(CicularBufferContext * context, u_int8_t *data, u_int8_t len)
{
	if(context->currWriteIndex >= MAX_NUM_OF_PACKETS)
	{
		context->currWriteIndex = 0;
	}
	memcpy(buffer[context->currWriteIndex].buf, data, len);
	buffer[context->currWriteIndex].length = len;
	context->currWriteIndex++;

	return 0;
}

u_int8_t *popFromCircularBuffer(CicularBufferContext * context, u_int8_t *readBuff, u_int8_t *len)
{
	if(context->currReadIndex >= MAX_NUM_OF_PACKETS)
	{
		context->currReadIndex = 0;
	}
	memcpy(readBuff, buffer[context->currReadIndex].buf, buffer[context->currReadIndex].length);
	memcpy(len, &buffer[context->currReadIndex].length, sizeof(u_int8_t));
	memset(buffer[context->currReadIndex].buf,0,buffer[context->currReadIndex].length);
	buffer[context->currReadIndex].length = 0;
	context->currReadIndex++ ;
	return readBuff;
}

uint32_t getTotalDataLength(CicularBufferContext * context)
{
	uint32_t totalLength = 0;
  for(uint16_t index=0;index<MAX_NUM_OF_PACKETS;index++)
  {
    totalLength = totalLength+ buffer[index].length;
  }
  return totalLength;
}

void clearCircularBuffer(CicularBufferContext * context)
{
  context->currWriteIndex = 0;
  context->currReadIndex = 0;
  for(uint16_t index=0; index<MAX_NUM_OF_PACKETS; index++)
  {
    memset(buffer[index].buf, 0 , LENGTH_OF_PACKET);
    buffer[index].length = 0;
  }
}

#ifdef TESTING
	u_int8_t getcurrWriteIndex(CicularBufferContext * context)
	{
		return context->currWriteIndex;
	}
	u_int8_t getcurrReadIndex(CicularBufferContext * context)
	{
		return context->currReadIndex;
	}
	void printData(CicularBufferContext * context)
	{
		for(int i = 0;i<MAX_NUM_OF_PACKETS;i++){
			for(int dataIndex = 0;dataIndex<buffer[i].length;dataIndex++)
			{

			}
		}
	}
#endif
