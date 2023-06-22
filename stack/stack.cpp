#include <iostream>
#define SIZE 10
using namespace std;

class stack{
private:
    char stck[SIZE];
    int index;
public:
    stack();
    void push(char ch);
    char pop();
};

stack::stack(){
    index = 0;
}

void stack::push(char ch){
    if(index==SIZE){
	cout << "Стек переполнен";
	return;
    }
    stck[index] = ch;
    index++;
}

char stack::pop(){
    if(index == 0){
	cout << "Стек пуст";
 	return 0;
    }
    index--;
    return stck[index];
}

int main(){

    stack s1;

    s1.push('S');

    cout << s1.pop() << "\n";

    return 0;
}
