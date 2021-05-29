#ifndef INCLUDE_TEXT_H_
#define INCLUDE_TEXT_H_
#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Node
{
	string val;
	Node* next;
	Node* down;
	int level = 0;
};

class Text
{
private:
	Node* head;
	Node* curr;
	stack<Node*> path;
	void deleteBranch(Node* node);

public:
	Text();
	void GoHead();
	void next();
	void down();
	void top();

	string GetCurr();
	void SetCurr(string str);
	Node* GetCurrNode();
	Node* GetHeadNode();

	void addNext(string str);
	void addDown(string str);
	void deleteCurr();
	void deleteDown();

	//dop
	void moveCurr();

	void print();
};

void print(Node* _head, Node* _curr, int level = 0);

#endif  
