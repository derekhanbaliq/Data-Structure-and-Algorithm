#pragma once
#include <iostream>
#include "config.h"

using namespace std;

//˳��ջS�ĳ�ʼ��
Status InitStack(SqStack& S);

//�ж�˳��ջS�Ƿ�Ϊ��
Status IsStackEmpty(SqStack S);

//��ӡ˳��ջS - �Զ��庯��1
void PrintStack(SqStack S);

//���˳��ջS - �Զ��庯��2
Status FillStack(SqStack& S);

//��˳��ջS����
int StackLength(SqStack S);

//���˳��ջS
Status ClearStack(SqStack S);

//����˳��ջS
Status DestroyStack(SqStack& S);

//˳��ջS����ջ
Status Push(SqStack& S, SElemType e);

//˳��ջS�ĳ�ջ
Status Pop(SqStack& S, SElemType& e);
