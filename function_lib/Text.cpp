#include "Text.h"

Text::Text()
{
	curr = head = new Node();
}

void Text::GoHead()
{
	curr = head;
}

void Text::next()
{
	if (curr->next != nullptr)
	{
		path.push(curr);
		curr = curr->next;
	}
}

void Text::down()
{
	if (curr->down != nullptr)
	{
		path.push(curr);
		curr = curr->down;
	}
}

void Text::top()
{
	if (!path.empty())
	{
		curr = path.top();
		path.pop();
	}
}




string Text::GetCurr()
{
	return curr->val;
}

void Text::SetCurr(string str)
{
	curr->val = str;
}

Node* Text::GetCurrNode()
{
	return curr;
}

Node* Text::GetHeadNode()
{
	return head;
}


void Text::addNext(string str)
{
	Node* tmp = new Node();
	tmp->val = str;
	tmp->next = curr->next;
	curr->next = tmp;
	tmp->level = curr->level;
}

void Text::addDown(string str)
{
	Node* tmp = new Node();
	tmp->val = str;
	tmp->next = curr->down;
	curr->down = tmp;
	tmp->level = curr->level + 1;
}

void Text::deleteBranch(Node* node)
{
	stack<Node*> stack;
	if (node == nullptr) return;
	stack.push(node);
	while (!stack.empty())
	{
		Node* tmp = stack.top();
		stack.pop();
		if (tmp->down != nullptr)
			stack.push(tmp->down);
		if (tmp->next != nullptr)
			stack.push(tmp->next);
		if ((tmp->down == nullptr) && (tmp->next == nullptr))
			delete tmp;
	}
}

void Text::deleteCurr()
{
	deleteDown();
	Node* tmp = curr;
	if (tmp == head)
	{
		if (tmp->next != nullptr)
			head = tmp->next;
		else if (tmp->next != nullptr)
			head = tmp->down;
		else if ((tmp->down == nullptr) && (tmp->next == nullptr))
		{
			head->val = "";
			return;
		}
	}
	else
	{
		top();
		if (curr->next == tmp)
			curr->next = tmp->next;
		else
			curr->down = tmp->next;
	}
	delete tmp;
}

void Text::deleteDown()
{
	deleteBranch(curr->down);
	curr->down = nullptr;
}

void print(Node* _head, Node* _curr, int level)
{
	if (_head == nullptr) return;
	for (int i = 0; i < level; i++)
		cout << " ";
	cout << _head->val;
	if (_head == _curr) cout << " ->";
	cout << endl;
	print(_head->down, _curr, level + 1);
	print(_head->next, _curr, level);
}

void Text::print()
{
	stack<Node*> stack;
	stack.push(head);
	while (!stack.empty())
	{
		Node* tmp = stack.top();
		stack.pop();
		for (int i = 0; i < tmp->level; i++)
			cout << " ";
		cout << tmp->val;
		if (tmp == curr) cout << " ->";
		cout << endl;
		if (tmp->next != nullptr)
			stack.push(tmp->next);
		if (tmp->down != nullptr)
		{
			stack.push(tmp->down);
		}
	}
}

//dop

void Text::moveCurr()
{
	//deleteDown();
	Node* tmp = curr;
	Node* prev = curr;

	if (tmp == head)
		throw -1;
	else
	{
		top();
		if (curr->next == tmp)
			curr->next = tmp->next;
		else
			curr->down = tmp->next;
	}

	while (curr->down != prev)
	{
		prev = curr;
		top();
	}

	addNext(tmp->val);

	delete tmp;
}
