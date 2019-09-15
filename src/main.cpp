#include <iostream>
#include "Node.h"


int main(){
	int targetDepth;
	int branchingFactor;


	std::cout<<"Qual a profundidade da árvore?"<<std::endl;
	std::cin>>targetDepth;

	std::cout<<"Qual o fator de ramificação da árvore?"<<std::endl;
	std::cin>>branchingFactor;

	Node root = Node(0, targetDepth, branchingFactor);

	int* route = new int[targetDepth];

	std::cout<<std::endl;
	root.seekValue(route);

	std::cout<<"Melhor valor alcançado: "<<root.value<<std::endl;

	std::cout<<"rota utilizada: ";

	for(int i=0;i<targetDepth;i++){

		std::cout<< route[i] <<' ';
	}

	std::cout<<std::endl;

	root.destroyRecursive();

	delete[] route;

	return 0;
}