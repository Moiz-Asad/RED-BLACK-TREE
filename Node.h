#pragma once
#include"color.h"

struct TNode 
{
	int Data;
	int DuplicateCount = 0;
	TNode *Parent;
	TNode *LeftChild;
	TNode *RightChild;
	NodeColor Color;
	TNode()
	{

	}
	TNode(NodeColor C)
	{
		this->Color = C;
		this->LeftChild = nullptr;
		this->RightChild = nullptr;
		this->Parent = nullptr;
	}
	TNode(int Data,TNode* Par,NodeColor C,int DUP)
	{
		this->Data = Data;
		this->Parent = Par;
		this->DuplicateCount = DUP;
		this->LeftChild = new TNode(BLACK);
		this->RightChild = new TNode(BLACK);
		this->Color = C;
	}
};
