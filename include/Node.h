#ifndef NODE_H
#define NODE_H

#define MIN  0
#define MAX  1
#define LEAF 2

typedef int Type;

class Node {
public:
	int childCount;
	int value;
	int depth;
	Type nodeType;
	Node** childs;

	bool untouched;

	int myChoice;

	Node();
	Node(int, int, int, bool);

	void seekValue();
	void destroyRecursive();
};

#endif
