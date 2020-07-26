#pragma once
#include<iostream>
#include"Node.h"
#include<string>
#include<fstream>
using namespace std;

class RedBlackTree
{
	// -> Attributes
	TNode* Root;
	TNode* NRoot;

	// -> Functions
	void LNRTriversal(TNode*);
	void RNLTriversal(TNode*);
	void RLNTriversal(TNode*);
	void LRNTriversal(TNode*);
	void NLRTriversal(TNode*);
	void NRLTriversal(TNode*);
	void PrintDup(int,int,NodeColor);
	void RootCreator(TNode*&, int);
	void TreeBalancer(TNode*);
	void RRotate(TNode*);
	void LRotate(TNode*);
	void DUPremove(TNode*);
	void CopyTree(TNode*&, TNode*);
	void DestroyTreeHelper(TNode* &);
	void Recoloring_Rotation(TNode*&,TNode*&,bool RT);
	TNode* SearchHelper(TNode*,int);
	void DeleteCasesHelper(TNode*, int Vs);
	void DeleteCaseSatifier(TNode*);
	void Recolor_Rotate_Left(TNode*&, TNode*&);
	void Recolor_Rotate_Right(TNode*&, TNode*&);
public:
	// Constructor
	RedBlackTree();
	RedBlackTree(RedBlackTree&);

	// Search
	TNode* SearchVal(int);
	bool IsExist(int);
	
	// File Read
	void ReadTree(string FName);

	// Triversals Print
	void InOrder(bool LNR = true);
	void PreOrder(bool NLR = true);
	void PostOrder(bool LRN = true);
	void ParentDisplay(int);

	// Remove Duplicates
	void AllDupRemover();

	// Insertion
	void Insert(int);

	//Delete
	void DeleteNode(int Vs);
	void ChangeChild(TNode*, TNode*);
	
	// Minimum
	TNode* GetMin(TNode*);

	// Distructor
	void DestroyAllNodes();
	TNode* RG(TNode*, int);
	void DeleteGreaterVal(int);
	
	~RedBlackTree();
};

