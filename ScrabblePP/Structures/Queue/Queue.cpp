#include "Queue.h"
#include <stdlib.h>

Queue::Queue()
{
	firstNode = nullptr;
	lastNode = nullptr;
	length = 0;
}

Queue::~Queue()
{
}

bool Queue::isEmpty()
{
	return firstNode == nullptr;
}

void Queue::push(char letter, int score)
{
	QueueNode *node = new QueueNode(letter, score);
	if (isEmpty())
	{
		firstNode = node;
		lastNode = node;
	}
	else
	{
		lastNode->setNextNode(node);
	}
	length++;
}

QueueNode *Queue::pop()
{
	if (!isEmpty())
	{
		QueueNode *node = firstNode;
		firstNode = firstNode->getNextNode();
		length--;
		return node;
	}
	return nullptr;
}

int Queue::getLength()
{
	return length;
}

void Queue::pushLetter()
{
	int a, b, c, d, e, f, g, h, i, j, l, m, n,
		enie, o, p, q, r, s, t, u, v, x, y, z;

	f = v = y = q = j = enie = x = z = 1;
	g = b = m = p = h = 2;
	l = t = c = 4;
	n = r = u = d = 5;
	i = s = 6;
	o = 9;
	a = e = 12;

	while (a != b != c != d != e != f != g != h != i != j != l != m != n != enie != o != p != q != r != s != t != u != v != x != y != z != 0)
	{
		switch (rand() % 26)
		{
		case 1:
			if (a > 0)
			{
				push('A', 1);
				a--;
			}
			break;
		case 2:
			if (e > 0)
			{
				push('E', 1);
				e--;
			}
			break;
		case 3:
			if (o > 0)
			{
				push('O', 1);
				o;
			}
			break;
		case 4:
			if (i > 0)
			{
				push('I', 1);
				i--;
			}
			break;
		case 5:
			if (s > 0)
			{
				push('S', 1);
				s--;
			}
			break;
		case 6:
			if (n > 0)
			{
				push('N', 1);
				n--;
			}
			break;
		case 7:
			if (l > 0)
			{
				push('L', 1);
				l--;
			}
			break;
		case 8:
			if (r > 0)
			{
				push('R', 1);
				r--;
			}
			break;
		case 9:
			if (u > 0)
			{
				push('U', 1);
				u--;
			}
			break;
		case 10:
			if (t > 0)
			{
				push('T', 1);
				t--;
			}
			break;
		case 11:
			if (d > 0)
			{
				push('D', 2);
				d--;
			}
			break;
		case 12:
			if (g > 0)
			{
				push('G', 2);
				g--;
			}
			break;
		case 13:
			if (c > 0)
			{
				push('C', 3);
				c--;
			}
			break;
		case 14:
			if (b > 0)
			{
				push('B', 3);
				b--;
			}
			break;
		case 15:
			if (m > 0)
			{
				push('M', 3);
				m--;
			}
			break;
		case 16:
			if (p > 0)
			{
				push('P', 3);
				p--;
			}
			break;
		case 17:
			if (h > 0)
			{
				push('H', 4);
				h--;
			}
			break;
		case 18:
			if (f > 0)
			{
				push('F', 4);
				f--;
			}
			break;
		case 19:
			if (v > 0)
			{
				push('V', 4);
				v--;
			}
			break;
		case 20:
			if (y > 0)
			{
				push('Y', 4);
				y--;
			}
			break;
		case 21:
			if (q > 0)
			{
				push('Q', 5);
				q--;
			}
			break;
		case 22:
			if (j > 0)
			{
				push('J', 8);
				j--;
			}
			break;
		case 23:
			if (enie > 0)
			{
				push('�', 8);
				enie--;
			}
			break;
		case 24:
			if (x > 0)
			{
				push('X', 8);
				x--;
			}
			break;
		case 25:
			if (z > 0)
			{
				push('Z', 10);
				z--;
			}
			break;
		}
	}
}