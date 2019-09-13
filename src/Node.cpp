#include <iostream>
#include <random>
#include "Node.h"

//maior valor possível para uma folha
#define MAXLEAFVALUE 100

int getRandom(int maxValue){
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, maxValue);
    return dist(rng);
}

Node::Node(){}

Node::Node(int currentDepth, int targetDepth, int branchingFactor){
	if(currentDepth == targetDepth){
		nodeType = LEAF;
		childCount = 0;
	}else{
		nodeType = (currentDepth % 2 ==  0)?(MAX):(MIN);
	}

	if(nodeType==LEAF){
		value = getRandom(MAXLEAFVALUE);
		std::cout<<value<<" ";
	}else{
		childCount = branchingFactor;

		childs =  new Node*[branchingFactor];

		for(int i=0;i < branchingFactor;i++){
			childs[i] = new Node(currentDepth + 1, targetDepth, branchingFactor);
		}
	}
}

/*
static void destroyRecursive(Node* node)
{  

    for(int i=0;i<node->childCount;i++){
    	destroyRecursive(node->childs[i]);
    }  

    delete node;  
}
*/