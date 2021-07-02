#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

/*
 * Struct for holding the write index and the read index of the buffer.
 * */
typedef struct sCicularBufferContext {
	/* index of buffer where data is written*/
	u_int8_t currWriteIndex;

	/* index of the buffer where data is read*/
	u_int8_t currReadIndex;
} CicularBufferContext;

/*********************************************************************
 * @fn      appendToCircularBuffer
 *
 * @brief   Write data to the buffer
 *
 * @param   data - data to be written in buffer.
            length - The length of data to be written.
 *
 * @return   0x00: success
             0x01: failure
 */
u_int8_t appendToCircularBuffer(CicularBufferContext * context, u_int8_t *data, u_int8_t length);

/*********************************************************************
 * @fn      popFromCircularBuffer
 *
 * @brief   Gives the data and the length of data from the buffer
 *
 * @param   readBuff - pointer to the buffer that stores retrieved data .
            length - The length of data to be return.
 *
 * @return   tempBuff: pointer to the read data
 */

u_int8_t *popFromCircularBuffer(CicularBufferContext * context, u_int8_t *readBuff, u_int8_t *length);

/*********************************************************************
 * @fn      getTotalDataLength
 *
 * @brief   Give the total length of the data stored in the buffer.
 *
 * @param   context - pointer to the circular buffer context .
 *  @return   totalLength: total length of the data in buffer.
 */
uint32_t getTotalDataLength(CicularBufferContext * context);
/*********************************************************************
 * @fn      clearCircularBuffer
 *
 * @brief   clear all data from the buffer
 *
 * @param   context - pointer to the circular buffer context .
 */
void clearCircularBuffer(CicularBufferContext * context);

#ifdef TESTING
/*********************************************************************
 * @fn      printData
 *
 * @brief   print the data of the buffer
 *
 * @param   context - pointer to the CicularBufferContext  .
 *
 * @return
 */
	void printData(CicularBufferContext * context);

	/*********************************************************************
	 * @fn      getcurrWriteIndex
	 *
	 * @brief   It returns the current index of the buffer where the recent data is written.
	 *
	 * @param   context - pointer to the CicularBufferContext  .
	 *
	 * @return currWriteIndex: index of the buffer where data is written.
	 */
	u_int8_t getcurrWriteIndex(CicularBufferContext * context);

	/*********************************************************************
	 * @fn      getcurrReadIndex
	 *
	 * @brief   It returns the current index of the buffer where the data is read.
	 *
	 * @param   context - pointer to the CicularBufferContext  .
	 *
	 * @return currReadIndex: index of the buffer from where data is read.
	 */
	u_int8_t getcurrReadIndex(CicularBufferContext * context);
#endif

#ifdef __cplusplus
}
#endif
#endif /* CIRCULARBUFFER_H_ */

