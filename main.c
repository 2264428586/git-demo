#include <stdio.h>
#include <string.h>
#include "main.h"

#define BUFFER_SIZE 100

// 环形缓冲区结构体
typedef struct {
    char buffer[BUFFER_SIZE];
    int head;
    int tail;
} CircularBuffer;

// 初始化环形缓冲区
void init_buffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
}

// 向环形缓冲区写入数据
void buffer_write(CircularBuffer *cb, const char *data, int length) {
    for (int i = 0; i < length; i++) {
        cb->buffer[cb->head] = data[i];
        cb->head = (cb->head + 1) % BUFFER_SIZE;
        if (cb->head == cb->tail) {
            cb->tail = (cb->tail + 1) % BUFFER_SIZE; // 覆盖旧数据
        }
    }
}

// 从环形缓冲区读取数据
void buffer_read(CircularBuffer *cb, char *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (cb->tail != cb->head) {
            buffer[i] = cb->buffer[cb->tail];
            cb->tail = (cb->tail + 1) % BUFFER_SIZE;
        } else {
            buffer[i] = '\0'; // 缓冲区为空
        }
    }
}

// 串口接收函数
void uart_receive(CircularBuffer *cb, char *buffer, int length) {
    // 模拟接收数据
    buffer_write(cb, "Received Data", strlen("Received Data"));
    buffer_read(cb, buffer, length);
}

// 串口发送函数
void uart_send(const char *data) {
    // 模拟发送数据
    printf("Sending: %s\n", data);
}

int main() {
    // 初始化代码
    printf("Hello, World!\n");

    // 初始化环形缓冲区
    CircularBuffer cb;
    init_buffer(&cb);

    // 主逻辑代码
    char buffer[BUFFER_SIZE];
    uart_receive(&cb, buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);

    const char *data_to_send = "Hello, UART!";
    uart_send(data_to_send);

    // 结束代码
    return 0;
}