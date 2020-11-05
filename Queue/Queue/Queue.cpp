// Queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define QUEUE_SIZE 11
typedef struct Queue
{
	int arr[QUEUE_SIZE];
	int font;
	int rear;
	int size;
}*PQueue, MyQueue;
void initQueue(Queue &que)
{
	int arr = { 0 };
	que.font = 0;
	que.rear = 0;
	que.size = 0;
}

bool queueIsFull(Queue &que)
{
	int t = (que.rear + 1) % QUEUE_SIZE;
	if (t == que.font)
	{
		return true;
	}
	return false;
}

bool queueAdd(Queue &que, int data)
{
	if (queueIsFull(que))
	{
		return false;
	}
	que.arr[que.rear] = data;
	que.rear = (que.rear + 1) % QUEUE_SIZE;
	que.size = (que.size + 1) / QUEUE_SIZE;
	return true;
}
bool queueDelete(Queue   &que)
{
	if (que.rear == que.font)
	{
		return false;
	}
	que.arr[que.font] = 0;
	que.font = (que.font + 1) % QUEUE_SIZE;
	que.size = que.size--;
	return true;
}
bool queueIsEmpty(Queue &que)
{
	return que.size == 0;
}
int main()
{
	MyQueue que;
	initQueue(que);
	queueAdd(que, 1);
	queueAdd(que, 2);
	queueAdd(que, 3);
	queueAdd(que, 4);
	queueAdd(que, 5);
	queueAdd(que, 6);
	queueDelete(que);
	queueDelete(que);
	queueAdd(que, 1);
	queueAdd(que, 2);
	queueAdd(que, 3);
	queueAdd(que, 4);
	queueAdd(que, 5);
	queueAdd(que, 6);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
