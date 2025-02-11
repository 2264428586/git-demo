#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

// 环形缓冲区结构体
typedef struct {
    char buffer[BUFFER_SIZE];
    int head;
    int tail;
} CircularBuffer;

// 初始化环形缓冲区
void init_buffer(CircularBuffer *cb);

// 向环形缓冲区写入数据
void buffer_write(CircularBuffer *cb, const char *data, int length);

// 从环形缓冲区读取数据
void buffer_read(CircularBuffer *cb, char *buffer, int length);

// 串口接收函数
void uart_receive(CircularBuffer *cb, char *buffer, int length);

// 串口发送函数
void uart_send(const char *data);

#endif // MAIN_H