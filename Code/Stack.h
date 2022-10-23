#include <string>
#include <iostream>
#include <vector>
//LIFO Last In - First Of
using namespace std;
struct Nodo{
    string data;
    Nodo* next;
    Nodo(string data);
    void setData(string data);
    void setNext(Nodo* next);
    string getData();
    Nodo* getNext();
};
class Stack{
    Nodo* head;
public:
    string pop();
    void push(string insert);
    void setHead(Nodo*);
    void printStack();
    Nodo* gethead();
    bool isempty();
    Stack();
};
vector<string> operation(string expresion);
string calculatePI(vector<string> operate);
string calculateP(vector<string> operate);
double calculator1(string operation, string fTerm, string lTerm);
