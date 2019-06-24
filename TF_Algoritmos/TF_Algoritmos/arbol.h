#pragma once
#include <functional>
#include <iostream>
#include <time.h>

using namespace std;

template <typename T>
class AVLTree
{

	struct Node
	{
		T		e;
		Node*	l;
		Node*	r;
		int		h;

		Node(T e, Node* l = nullptr, Node* r = nullptr, int h = 0)
			: e(e), l(l), r(r), h(h) {}
	};

	Node*	root;
	int		nElems;
	std::function<int(T, T)> comp;

	int Height(Node* n)
	{
		return n == nullptr ? -1 : n->h;
	}

	void updateH(Node* n)
	{
		int m = Height(n->l) > Height(n->r) ? Height(n->l) : Height(n->r);
		n->h = m + 1;
	}

	void rotR(Node*& n)
	{
		Node* aux = n->l;
		n->l = aux->r;
		aux->r = n;
		updateH(n);
		n = aux;
		updateH(n);
	}

	void rotL(Node*& n)
	{
		Node* aux = n->r;
		n->r = aux->l;
		aux->l = n;
		updateH(n);
		n = aux;
		updateH(n);
	}
	void Balance(Node*& n)
	{
		int hl = Height(n->l);
		int hr = Height(n->r);

		if (hl - hr < -1)
		{
			int hrl = Height(n->l);
			int hrr = Height(n->r);
			if (hrl > hrr)
			{
				rotR(n->r);
			}
			rotL(n);
		}

		else if (hl - hr > 1)
		{
			int hll = Height(n->l);
			int hlr = Height(n->r);
			if (hlr > hll)
			{
				rotL(n);
			}
			rotR(n);
		}
		else
			updateH(n);

	}

public:

	AVLTree(function<int(T, T)> comp) : root(nullptr), nElems(0), comp(comp) {}

	int Lenght()
	{
		return nElems;
	}

	int TreeHeight()
	{
		return Height(root);
	}


	void add(T e) {
		function<void(Node*&n)> ladd = [&](Node*& n) {
			if (n == nullptr) {
				n = new Node(e);
				nElems++;
			}
			else {
				if (comp(e, n->e) < 0) {
					ladd(n->l);
				}
				else {
					ladd(n->r);
				}

			}
			Balance(n);
		};
		ladd(root);
	}
};