#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node * pNext;
};

void printNode(Node* head)
{
	cout << head->value << " ";

	if (head->pNext == nullptr)
		return;

	printNode(head->pNext);
}

Node* insertNode(Node* pStart, Node* newNode,int nPlace)
{
	Node* curNode = pStart;

	for (int i = 0; i < nPlace-1; i++)
	{
		curNode = curNode->pNext;
	}

	Node* temp = curNode->pNext;

	curNode->pNext = newNode;

	newNode->pNext = temp;

	return pStart;
}

Node* deleteNode(Node* pStart, int nPlace)
{
	Node* curNode = pStart;

	Node* tempL = NULL;
	Node* tempR = NULL;

	for (int i = 0; i < nPlace-1; i++)
	{
		if (i == nPlace - 2)
			tempL = curNode;

		curNode = curNode->pNext;
	}

	tempR = curNode->pNext;
	tempL->pNext = tempR;
	
	delete curNode;

	return pStart;
}

int main()
{

	//0을 입력할때까지 입력을 받고 받은 입력을 그대로 출력

	Node* pStart = NULL;

	while (true)
	{
		int input = 0;
		cin >> input;

		if (input == 0)
			break;

		Node* pNew = new Node();
		pNew->value = input;
		pNew->pNext = nullptr;

		if (pStart == NULL)
		{
			pStart = pNew;
		}

		else
		{
			Node* pLast = pStart;
			while (true)
			{
				if (pLast->pNext == NULL)
					break;

				pLast = pLast->pNext;
			}
			pLast->pNext = pNew;
		}
	}
	

	printNode(pStart);

	cout <<endl<< "삭제 실험 3" << endl;
	deleteNode(pStart, 3);
	printNode(pStart);

	cout << endl << "삽입 실험 3" << endl;

	Node *test = new Node();

	test->value = 99;
	test->pNext = nullptr;

	insertNode(pStart, test, 3);
	printNode(pStart);


	
	system("pause");
	return 0;
}