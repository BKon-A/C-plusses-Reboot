#include <iostream>

using namespace std;

//��������� �������� ��� ������ � ��������������� �������� ��������.
//����� ������� ������ ������ ��������� �� ��������� � ���������
//�������� � ������.�������� �� ������������� �������� � �������� ������.
//�� �������� ��� ���������� ����������� ����� ����������������
//��������� ���������� �� �����.
//-----------------------------VARIANT 4----------------------------------
//������� ��������, ��� ������ ������� ���������� ��� ������ ������ ��
//������ ��������.
//����� ������ ������ :
//� ����� �����������;
//� ���� �����;
//� ��� �����������;
//� ������� ����.
//�������� ������� ������������� :
//� ��������� ��� ������ � ������ ������;
//� ��������� � ��������� ������;
//� �� ������� ����� ����������� � ����� ����� ��������� ������ � ��
//��������� ����������;
//� ��������� ��� ������.

struct List
{
	string statement;

	struct List* previous;
	struct List* next;
};

struct List* initialize(string data)
{
	List* p1st = new List;

	p1st->statement = data;
	p1st->previous = NULL;
	p1st->next = NULL;
	return p1st;
}

struct List* addNode(List* pNode, string data)
{
	List* temp = new List;

	List* vault = pNode->next; // ���������� ��������� �� ��������� �����

	pNode->next = temp; // ��������� ����� ������ �� ���������
	temp->statement = data; // ���������� ����
	temp->previous = pNode; // ����� ����� ������ �� ���������
	temp->next = vault; // ����� ����� ������ �� ���������

	if (vault != NULL)
		vault->previous = temp;

	return temp;
}

struct List* deleteNode(List* pNode)
{
	struct List* prev, * nxt;

	prev = pNode->previous;
	nxt = pNode->next;

	if (prev != NULL)
		prev->next = pNode->next; // ������������ ���������
	if (nxt != NULL)
		nxt->previous = pNode->previous; // ������������ ���������

	delete pNode;

	return nxt;
}

struct List* deleteRoot(List* root)
{
	struct List* temp;

	temp = root->next;
	temp->previous = NULL;

	delete root;

	return temp;
}

void print(List *pNode)
{
	int i = 0;
	struct List* temp;
	temp = pNode;

	do
	{

		cout << "Statement " << i << "\n";
		temp = temp->next;

	} while (temp != NULL);
}

int main()
{
	return 0;
}

class Data
{
	
};