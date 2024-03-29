#include <iostream>
#include <random>
#include "Node.h"

// maior valor possível para uma folha
#define MAXLEAFVALUE 100

int getRandom(int maxValue) {
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, maxValue);
    return dist(rng);
}

Node::Node(){}

Node::Node(int currentDepth, int targetDepth, int branchingFactor, bool printValue) {
	if(currentDepth == targetDepth) {
		nodeType = LEAF;
		childCount = 0;
	} else {
		nodeType = (currentDepth % 2 ==  0) ? (MAX) : (MIN);
	}

	if(nodeType==LEAF) {
		value = getRandom(MAXLEAFVALUE);
		if(printValue) std::cout << value << " ";
	} else {
		childCount = branchingFactor;
		untouched = true;

		childs = new Node*[branchingFactor];

		for(int i = 0; i < branchingFactor; i++) {
			childs[i] = new Node(currentDepth + 1, targetDepth, branchingFactor, printValue);
		}
	}
}


void Node::destroyRecursive()
{  
	if(nodeType != LEAF) {
	    for(int i=0; i < childCount; i++){
            if(childs[i] != nullptr) { childs[i]->destroyRecursive(); }
	    }
	}

	delete[] childs;
}

void Node::seekValue(){

	if(nodeType==LEAF) {
		return;
	} else if(nodeType==MAX) {
		for(int i=0; i< childCount; i++) {
	    	childs[i]->seekValue();
	    }
	    for(int i = 0; i< childCount; i++) {
	    	if(childs[i]->value > value || untouched) {
	    		value = childs[i]->value;
	    		untouched = false;
	    		myChoice = i;
	    	}
	    }
	}else if(nodeType==MIN) {
		for(int i = 0; i < childCount; i++) {
	    	childs[i]->seekValue();
	    }
	    for(int i = 0; i < childCount; i++) {
	    	if(childs[i]->value < value || untouched) {
	    		value = childs[i]->value;
	    		untouched = false;
	    		myChoice = i;
	    	}
	    }
	}
}
