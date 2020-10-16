/*
 *
 *
 *  Created on: Oct 16, 2020
 *      Author: absaki
 */
#include "my_queue.h"

int queue_init(t_ringbuff *buff)
{
	for (int i = 0; i < QUEUE_SIZE; i++)
	{
		buff->data[i] = 0;
	}
	buff->head = 0;
	buff->tail = 0;
	buff->count = 0;
	buff->isfull = 0;

	return 0;
}

int queue_enqueue(t_ringbuff *buff, unsigned char value)
{
	if (buff->isfull == 0 && ++(buff->count) <= QUEUE_SIZE)
	{
		buff->data[buff->tail] = value;
		if (buff->tail == QUEUE_SIZE - 1)
			buff->tail = 0;
		else
			buff->tail += 1;
		return 0;
	}
	else
		return (buff->isfull = 1);
}

int queue_dequeue(t_ringbuff *buff)
{
	if (buff->count > 0 && buff->isfull == 0)
	{
		int head_tmp = buff->head;
		if (head_tmp == QUEUE_SIZE - 1)
			buff->head = 0;
		else
			buff->head += 1;
		buff->count -= 1;
		return buff->data[head_tmp];
	}
	return -1;
}
