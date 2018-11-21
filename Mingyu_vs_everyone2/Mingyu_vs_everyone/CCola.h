#pragma once
#include<functional>

template<typename T>
class CCola
{
	struct Nodo
	{
		T elem;
		Nodo*next;
	Nodo(T elem, Nodo* next = nullptr) :elem(elem), next(next){}

	};
	Nodo* first;
	Nodo* last;
	short size;
public:
	CCola(Nodo* first = nullptr, Nodo* last = nullptr,short size = 0) : 
    first(first), last(last),size(0){}
	void add(T elem) {
		if (first == nullptr)
		{
			Nodo* nuevo = new Nodo(elem,first);
			first = nuevo;
			last = nuevo;
			size++;
		}
		else
		{   
			Nodo* aux = last;
			Nodo* nuevo = new Nodo(elem);
			aux->next = nuevo;
			last = nuevo;
		}
	}
	T desencolar() {
		Nodo* aux = first;
		first = aux->next;
		return aux->elem;
	}
};




