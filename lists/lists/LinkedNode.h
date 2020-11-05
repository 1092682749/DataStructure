#pragma once
/*
	List的单向链表实现
*/
template <class T>
class LinkedNode
{
public:
	T value;
	LinkedNode *next;
	LinkedNode(T value) {
		this->value = value;
		next = nullptr;
	}
	LinkedNode() {
		// value = default();
		next = nullptr;
	}
};


template <class T>
class LinkedList
{
public:
	LinkedNode<T> *head;
	LinkedList(LinkedNode<T> *head) {
		this->head = head;
	}

	// 尾插法
	bool add(LinkedNode<T> *node)
	{
		// 滑动指针
		LinkedNode<T> *temp = this->head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = node;
		return true;
	}
	bool add(T t)
	{
		LinkedNode<T> *node = new LinkedNode<T>(t);
		this->add(node);
		return true;
	}
	// 头插法
	bool addAtHead(LinkedNode<T> *node)
	{
		if (node == nullptr)
		{
			return false;
		}
		if (this->head->next == node)
		{
			return true;
		}
		node->next = this->head->next;
		this->head->next = node;
		return true;
	}
	int size()
	{
		if (checkLoop() != nullptr)
		{
			// 存在闭环则返回-1
			return -1;
		}
		LinkedNode<T> *temp;
		temp = this->head;
		int size = 0;
		while (temp != nullptr)
		{
			size++;
			temp = temp->next;
		}
		return size;
	}

	LinkedNode<T>* checkLoop()
	{
		LinkedNode<T> *fast, *slow;
		fast = this->head;
		slow = this->head;

		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow)
			{
				std::cout << "存在闭环，相遇点的值：" << fast->value << std::endl;
				fast = this->head;
				while (fast != slow)
				{
					fast = fast->next;
					slow = slow->next;
				}
				std::cout << "环入口值: " << fast->value << std::endl;
				return fast;
			}
		}
		return nullptr;
	}
	// 倒置链表
	void reverse()
	{
		LinkedNode<T> *temp = this->head->next;
		this->head->next = nullptr;
		while (temp != nullptr)
		{
			LinkedNode<T> * t = temp;
			temp = temp->next;
			this->addAtHead(t);
		}
	}

	void foreach( void(*fun)(T item, int index)) const
	{

		LinkedNode<T> *temp = this->head->next;
		int i = 0;
		while (temp != nullptr)
		{
			
			fun(temp->value, i++);
			temp = temp->next;
		}

	}
	template<typename V> 
	LinkedList<V> map(V(*fun)(T item, int index))
	{
		LinkedList<V> newList(new LinkedNode<V>());

		LinkedNode<T> *temp = this->head->next;
		int i = 0;
		while (temp != nullptr)
		{

			V res = fun(temp->value, i++);
			newList.add(res);
			temp = temp->next;
		}
		return newList;
	}

	//template<typename V, typename FUN>
	//LinkedList<V> map(FUN const& fun)
	//{
	//	LinkedList<V> newList(new LinkedNode<V>());
	//	LinkedNode<T> *temp = this->head->next;
	//	int i = 0;
	//	while (temp != nullptr)
	//	{

	//		V res = fun(temp->value, i++);
	//		newList.add(res);
	//		temp = temp->next;
	//	}
	//	return newList;
	//}

	

};


