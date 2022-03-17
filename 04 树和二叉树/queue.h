#pragma once
#include <iostream>
#include "config.h"

using namespace std;

//初始化队列Q
Status InitQueue(SqQueue& Q);

//求队列Q的长度
int QueueLength(SqQueue Q);

//循环队列Q入队
Status EnQueue(SqQueue& Q, QElemType e);

//循环队列Q出队
Status DeQueue(SqQueue& Q, QElemType& e);

//打印队列Q
void PrintQueue(SqQueue Q);

//取Q队头元素
QElemType GetHead(SqQueue Q);
