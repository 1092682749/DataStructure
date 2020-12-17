// KMP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

// 这个算法一个难以想到的点：算法假定=>当比较i个元素的时候，从i往前数j个元素已经是 相等的/匹配的
void get_next(char str[], int next[])
{
	int len = strlen(str);
	
	int i = 1, j = 0;
	next[1] = 0;
	while (i < len)
	{
		if (j == 0 || str[i] == str[j])
		{
			i++; j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
	// return next;
}
int main()
{
	char str[7] = { '$','a', 'a', 'b', 'c', 'd', '\0'};
	int next[6];
	next[0] = 0;
	get_next(str, next);
	
	for (int i = 0; i < 6; i++)
	{
		std::cout << next[i] << std::endl;
	}
    std::cout << "Hello World!\n"; 
}
// 部分匹配表计算方法：

// 前缀：不包含最后一个字符的所有字符串

// 后缀不包含第一个字符的所有字符串

//KMP算法简单思路

// KMP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

//



#include <iostream>

class KMPString

{

public:

	char *value, *compare;

	int *next = nullptr;

	KMPString(char *str) {

		this->value = str;

	}

	void setCompare(char *com)

	{

		this->compare = com;

	}

	int getIndex()

	{

		int i = 0, j = 0;

		std::cout << "compare length::" << strlen(compare) << "\n";

		while (j <= strlen(compare) >= 1)

		{

			if (i > strlen(this->value) - 1) break;

			std::cout << "i is::" << value[i] << " |#|j is::" << compare[j] << "\n";

			if (value[i] == compare[j])

			{

				i++;

				j++;

			}
			else if (i == 0) // 不相等且为第0个元素，则让j指针往前移动

			{

				j++;

			}

			else  // 则就要去找到回溯

			{

				i = getBacktracking(i);

			}

		}

		if (j >= strlen(compare))

		{

			j = -1;

		}

		else

		{

			j -= strlen(this->value);

		}

		return j;

	}

private:

	int getBacktracking(int position)

	{

		if (this->next == nullptr)

		{

			this->next = (int*)malloc(sizeof(int) * strlen(this->value));

			memset(this->next, -1, sizeof(*(this->next)));

			this->next[0] = 0;

			this->next[1] = 0;

		}

		if (this->next[position] == -1)

		{

			this->next[position] = getNext(position);

		}

		return this->next[position];

	}



	int getNext(int position)

	{

		int count = 0;

		for (int p = 0; p < position - 1; p++)

		{

			char *prefix = (char*)malloc(sizeof(char) * (position - 1 - p)), *suffix = (char*)malloc(sizeof(char) * (position - 1 - p));

			memcpy(prefix, this->value, position - 1 - p);

			memcpy(suffix, (this->value) + p, position - 1);

			if (strcmp(prefix, suffix) == 0)

			{

				count++;

			}

		}

		return count;

	}



};

int main()

{

	//char *s = ;

	KMPString s((char*)"ababcdabcd");

	s.setCompare((char*)"basasaaababcdabcdsaaasaasas");

	std::cout << s.getIndex();

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
