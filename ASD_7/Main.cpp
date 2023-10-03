#include <iostream>

using namespace std;

//Розробити програму для роботи з двонаправленими зв’язними списками.
//Кожен елемент списку містить посилання на наступний і попередній
//елементи у списку.Програма має забезпечувати введення і побудову списку.
//Всі операції над динамічними структурами мають супроводжуватися
//відповідним виведенням на екран.
//-----------------------------VARIANT 4----------------------------------
//Скласти програму, яка містить поточну інформацію про заявки квитків на
//міжміські автобуси.
//Кожна заявка містять :
//• пункт призначення;
//• дату виїзду;
//• час відправлення;
//• кількість місць.
//Програма повинна забезпечувати :
//• зберігання всіх заявок у вигляді списку;
//• додавання і видалення заявок;
//• за заданим часом відправлення і датою виїзду виведення заявок з їх
//подальшим видаленням;
//• виведення всіх заявок.

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

	List* vault = pNode->next; // збереження покажчика на наступний вузол

	pNode->next = temp; // попередній вузол показує на наступний
	temp->statement = data; // збереження поля
	temp->previous = pNode; // новий вузол показує на попередній
	temp->next = vault; // новий вузол показує на наступний

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
		prev->next = pNode->next; // перестановка покажчика
	if (nxt != NULL)
		nxt->previous = pNode->previous; // перестановка покажчика

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