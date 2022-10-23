#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Stack.h"

using namespace std;

Nodo::Nodo(string data) {
    this -> data = data;
    this -> next = NULL;
}
void Nodo::setData(string data) {
    this -> data = data;
}
void Nodo::setNext(Nodo* next){
    this -> next = next;
}
string Nodo::getData() {
    return this -> data;
}
Nodo* Nodo::getNext() {
    return this -> next;
}
Stack::Stack() {
    this -> head = NULL;
}
void Stack::setHead(Nodo* head) {
    this -> head = head;
}
Nodo* Stack::gethead() {
    return this -> head;
}
void Stack::printStack() {
    Nodo* actualy = this -> head;
    while (this -> head != NULL) {
        cout << actualy -> getData() << " -> ";
        if(actualy -> next == NULL){
            break;
        }
        actualy = actualy -> next;
    }
    cout << "NULL" << endl;
}
void Stack::push(string insert) {
   if(this -> head == NULL){
       Nodo* nHead = new Nodo(insert);
       setHead(nHead);
   }else{
       Nodo* nInsert = new Nodo(insert);
       nInsert ->setNext(this -> head);
       this -> head = nInsert;
   }
}
string Stack::pop() {
    string value = this -> head -> getData();
    this -> head = this -> head -> next;
    return value;
}
bool Stack::isempty(){
    if (this -> head == NULL){
        return true;
    }
    return false;
}
vector<string> operation(string expresion){
    string txt = "";
    bool isUnique = true;
    vector<string> operation;
    for (int i = 0;  i < expresion.length(); i++) {
        if (expresion.substr(i, 1) == "("){
            isUnique = false;
            continue;
        }
        if (expresion.substr(i, 1) == ")"){
            operation.push_back(txt);
            txt = "";
            isUnique = true;
            continue;
        }
        if (isUnique == true){
            string subS = expresion.substr(i, 1);
            operation.push_back(subS);
        } else {
            txt += expresion.substr(i, 1);
        }
    }
    return operation;
}
string calculatePI(vector<string> operate){
    Stack stack = Stack();
    while (!operate.empty()){
        if (operate.front() == "+" || operate.front() == "-" || operate.front() == "/" || operate.front() == "*" ){
            string termA = stack.pop();
            string termB = stack.pop();
            string operation = operate.front();
            operate.erase(operate.begin());
            double proced = calculator1(operation, termB, termA);
            string add = to_string(proced);
            stack.push(add);
        } else {
            stack.push(operate.front());
            operate.erase(operate.begin());
        }
    }
    return stack.gethead()->getData();
}
string calculateP(vector<string> operate) {
    Stack stack = Stack();
    string actual;
    int terminales = 0;
    while (!operate.empty()){
        actual = operate.front();
        operate.erase(operate.begin());
        try {
            stod(actual);
            stack.push(actual);
            terminales += 1;
            if (terminales == 2){
                string termA = stack.pop();
                string termB = stack.pop();
                string operation = stack.pop();
                double proced = calculator1(operation, termB, termA);
                string add = to_string(proced);
                stack.push(add);
                terminales = 1;
            }
        }
        catch (invalid_argument){
            stack.push(actual);
            terminales = 0;
        }
    }
    string retorno = stack.pop();
    if (!stack.isempty()){
        string termB = stack.pop();
        string operation = stack.pop();
        double proced = calculator1(operation, termB, retorno);
        string add = to_string(proced);
        retorno = add;
    }
    return retorno;
}

double calculator1(string operation, string fTerm, string lTerm){
    if(operation == "+"){
        double result = stod(fTerm) + stod(lTerm);
        return result;
    }
    if(operation == "*"){
        double result = stod(fTerm) * stod(lTerm);
        return result;
    }
    if(operation == "/"){
        double result = stod(fTerm) / stod(lTerm);
        return result;
    }
    if(operation == "-"){
        double result = stod(fTerm) - stod(lTerm);
        return result;
    }
}
