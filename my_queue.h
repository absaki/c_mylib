/*
 * 
 *
 *  Created on: Oct 16, 2020
 *      Author: absaki
 */

#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <stdint.h>

#define QUEUE_SIZE 16

typedef struct
{
	uint16_t head;
	uint16_t count;
	uint16_t tail;
	unsigned char data[QUEUE_SIZE];
	uint8_t isfull;
} t_ringbuff;

int queue_init(t_ringbuff *buff);
int queue_enqueue(t_ringbuff *buff, unsigned char value);
int queue_dequeue(t_ringbuff *buff);


#endif 
