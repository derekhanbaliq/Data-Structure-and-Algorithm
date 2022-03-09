#pragma once
#include <iostream>
#include "config.h"

using namespace std;

//��ʼ������Q
Status InitQueue(SqQueue& Q);

//�����Q�ĳ���
int QueueLength(SqQueue Q);

//ѭ������Q���
Status EnQueue(SqQueue& Q, QElemType e);

//ѭ������Q����
Status DeQueue(SqQueue& Q, QElemType& e);

//��ӡ����Q
void PrintQueue(SqQueue Q);

//ȡQ��ͷԪ��
QElemType GetHead(SqQueue Q);
