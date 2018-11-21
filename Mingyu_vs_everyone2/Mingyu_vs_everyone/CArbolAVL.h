#pragma once
#include <functional>
#include<iostream>
#include <conio.h>
#include<math.h>

using namespace std;

template<typename T>
class AVLTree {
	struct Node {
		T       e;
		Node*   l;
		Node*   r;
		int     h;

		Node(T e) : e(e), l(nullptr), r(nullptr), h(0) {}
	};
	Node*   root;
	int     nElems;
	std::function<int(T, T)> comp;
	int nodeHeight(Node* n) {
		return n == nullptr ? -1 : n->h;
	}
	void updateHeight(Node* n) {
		int hl = nodeHeight(n->l);
		int hr = nodeHeight(n->r);
		int max = hl > hr ? hl : hr;
		n->h = max + 1;
	}
	void rotR(Node*& n) {
		Node* aux = n->l;
		n->l = aux->r;
		aux->r = n;
		updateHeight(n);
		n = aux;
		updateHeight(n);
	}
	void rotL(Node*& n) {
		Node* aux = n->r;
		n->r = aux->l;
		aux->l = n;
		updateHeight(n);
		n = aux;
		updateHeight(n);
	}
	void balance(Node*& n) {
		int hl = nodeHeight(n->l);
		int hr = nodeHeight(n->r);
		if (hl - hr < -1) {
			int hrl = nodeHeight(n->r->l);
			int hrr = nodeHeight(n->r->r);
			if (hrl > hrr) {
				rotR(n->r);
			}
			rotL(n);
		}
		else if (hl - hr > 1) {
			int hll = nodeHeight(n->l->l);
			int hlr = nodeHeight(n->l->r);
			if (hlr > hll) {
				rotL(n->l);
			}
			rotR(n);
		}
		else {
			updateHeight(n);
		}
	}
	void add(Node*& n, T e) {
		if (n == nullptr) {
			n = new Node(e);
			++nElems;
		}
		else {
			if (comp(e, n->e) < 0) {
				add(n->l, e);
			}
			else {
				add(n->r, e);
			}
			balance(n);
		}
	}
	Node* search(Node*& n, T e) {
		if (comp(e, n->e) < 0) {
			search(n->l, e);
		}
		else if (comp(e, n->e) > 0) {
			search(n->r, e);
		}
		else {
			if (comp(e, n->e) == 0)
				return n;
		}
	}



public:
	AVLTree(std::function<int(T, T)> comp)
		: comp(comp), root(nullptr), nElems(0) {}
	int lenght() {
		return nElems;
	}
	int height() {
		return nodeHeight(root);
	}
	void add(T e) {
		add(root, e);
	}
	Node* search(T e) {
		return search(root, e);
	}
};
template<typename T>
class Pila {
	struct Node
	{
		T elem;
		Node* next;
		Node* left;
		Node(T elem, Node* next = nullptr, Node* left = nullptr) :elem(elem), next(next), left(left) {}
	};
	Node* first;
	Node* last;
	short cant;
public:
	Pila(Node*first = nullptr, Node*last = nullptr, short cant = 0) :first(first), last(last), cant(cant) {}
	bool isEmpty() {
		if (first == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(T elem) {
		if (first == nullptr)
		{
			Node* Nuevo = new Node(elem, nullptr, nullptr);
			nuevo = first;
			nuevo = last;
			cant++;
		}
		else
		{
			Node* aux = last;
			Node* nuevo = new Node(elem, nullptr, nullptr);
			if (aux->next == nullptr)
			{
				aux->next = nuevo;
				nuevo->left = aux;
				nuevo = last;
				cant++;
			}
		}
	}
	void Pop() {
		Node* aux = last;
		last = aux->left;
		delete aux;
		cant--;
	}
	T top() {
		Node* aux = last;
		return aux->elem;

	}
};







