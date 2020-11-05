#pragma once
template<typename T>
class StrackNode
{
	T value;
	StrackNode *next;
	StrackNode()
	{

	}
	StrackNode(T value)
	{
		this->value = value;
	}

	bool operator> (const StrackNode<T> &b)
	{
		int thisLen = 0;
		int bLen = 0;
		while (this->next != nullptr)
		{
			thisLen++;
		}
		StrackNode<T *pb = &b;
		while (pb->next != nullptr)
		{
			bLen++;
		}
		return thisLen > bLen;
	}
};
template<typename T>
class Strack
{
	StrackNode *head;


};

