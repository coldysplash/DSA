#include <iostream>

using namespace std;

class Node {
	public:
		Node *pnext;
		int data;
		Node(int data, Node *pNext = nullptr) {
			this->data = data;
			this->pnext = pNext;
		}
};

//Список
class List {
protected:
	Node *head;
	int Size;
public:
	List();
	~List();

	static int countpopfront;
    void AddFront(int data); // Добавление в начало
	void AddEnd(int data); // Добавление в конец 
	int GetSize(){return Size;} 
	int operator[](const int index);// Поиск элемента по индексу 
	void clear();
	void pop_front();// Удаление первого элемента
};

int List::countpopfront = 0;

List::List() {
	Size = 0;
	head = nullptr;
}

List::~List() {
	clear();
}

void List::AddFront(int data) {
	head = new Node(data, head);
	Size++;
}

void List::AddEnd(int data) {
	if (head == nullptr) {
		head = new Node(data);
	}
	else {
		Node *cur = this->head;

		while (cur->pnext != nullptr)
		{
			cur = cur->pnext;
		}
		cur->pnext = new Node(data);
	}
	Size++;
}

int List::operator[](const int index)
{
	if(index < 0 || index > Size){
		throw index;
	}
	int counter = 0;
	Node *cur = this->head;
	while (cur != nullptr) {
		if (counter == index) {
			return cur->data;
		}
		cur = cur->pnext;
		counter++;
	}
	return 0;
}

void List::pop_front(){
	Node *temp = head;
	head = head->pnext;
	delete(temp);
	Size--;
	countpopfront++;
}

void List::clear(){
	while(Size){
		pop_front();
	}
}

//Стек
class Stack:public List{
public:
	Stack();
	~Stack();
};

Stack::Stack(){
	Size = 0;
	head = nullptr;
}


Stack::~Stack(){
	clear();
}

//Очередь
class Queue:public List{
public:
	Queue();
	~Queue();
};

Queue::Queue(){
	Size = 0;
	head = nullptr;
}
Queue::~Queue(){
	clear();
}

int main() {

	List list;
	Stack stack, stack1, stack2; 
	Queue queue;

	int choose = 0, index = 0;
	cout << "[1] - Список\n";
	cout << "[2] - Стек\n";
	cout << "[3] - Очередь\n>>";
	cin >> choose;
	if(choose == 1){
		cout << "<<List>>\n";
		list.AddEnd(10);
		list.AddEnd(15);
		list.AddEnd(20);
		list.AddFront(100);
		for(int i = 0; i < list.GetSize(); i++){
			cout <<"["<< i <<"]-";
			cout << list[i] << " ";
		}
		cout << "\nSize - " << list.GetSize()<< "\n";
		cout << "Введите индекс элемента >> ";
		cin >> index;
		try{
			cout << "Value - "<< list[index] << "\n";
		}
		catch(const int ex){
			cout << "\nЭлемента под этим индексом не существует!\n";
		}
	}else if(choose == 2){
		cout << "<<Stack>>\n";
		stack1.AddFront(1);
		stack1.AddFront(2);
		stack1.AddFront(3);
		stack2.AddFront(4);
		stack2.AddFront(5);
		stack2.AddFront(6);
		for(int i = stack1.GetSize() - 1; i >= 0; i--){
			stack.AddFront(stack1[i]);
		}
		for(int i = stack2.GetSize() - 1; i >= 0; i--){
			stack.AddFront(stack2[i]);
		}
		for(int i = 0; i < stack.GetSize(); i++){
			cout << stack[i] << "\n";
		}
		cout << "после работы pop_front\n";
		stack.pop_front();
		for(int i = 0; i < stack.GetSize(); i++){
			cout << stack[i] << "\n";
		}
		cout << "\nКол-во извлеченных элементов - "<< list.countpopfront << "\n";
	}else if(choose == 3){
		cout << "<<Queue>>\n";
		queue.AddEnd(10);
		queue.AddEnd(15);
		queue.AddEnd(20);
		for(int i = 0; i < queue.GetSize(); i++){
			cout << queue[i] << " ";
		}
		cout << "\nпосле работы pop_front\n";
		queue.pop_front();
				for(int i = 0; i < queue.GetSize(); i++){
			cout << queue[i] << " ";
		}
		cout << "\n";
		cout << "\nКол-во извлеченных элементов - "<< list.countpopfront << "\n";
	}
	return 0;
}
