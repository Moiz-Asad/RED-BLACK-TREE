#include "RedBlackTree.h"


RedBlackTree::RedBlackTree()
{
	NRoot = new TNode;
	NRoot->Color = BLACK;
	NRoot->LeftChild = nullptr;
	NRoot->RightChild = nullptr;
	Root = NRoot;
	Root->DuplicateCount = 0;
}
RedBlackTree::RedBlackTree(RedBlackTree &TR)
{
	CopyTree(this->Root,TR.Root);
}
void RedBlackTree::LNRTriversal(TNode* L)
{
	if (L->LeftChild != nullptr || L->RightChild != nullptr)
	{
		LNRTriversal(L->LeftChild);
		cout << "\t\t";
		cout << L->Data;
		if (L->Color == RED)
		{
			cout << "(" << "RED" << ")" << endl;
		}
		else
		{
			cout << "(" << "BLACK" << ")" << endl;
		}
		if (L->DuplicateCount > 0)
		{
			PrintDup(L->Data, L->DuplicateCount , L->Color);
		}
		LNRTriversal(L->RightChild);
	}
	else
	{
		return;
	}
}
void RedBlackTree::RNLTriversal(TNode* L)
{
	
	if (L->LeftChild != nullptr || L->RightChild != nullptr)
	{
		RNLTriversal(L->RightChild);
		cout << "\t\t";
		cout << L->Data << " ";
		if (L->Color == RED)
		{
			cout << "(" << "RED" << ")" << " ";
		}
		else
		{
			cout << "(" << "BLACK" << ")" << " ";
		}
		if (L->DuplicateCount > 0)
		{
			PrintDup(L->Data, L->DuplicateCount, L->Color);
		}
		RNLTriversal(L->LeftChild);
	}
	else
	{
		return;
	}
}
void RedBlackTree::RLNTriversal(TNode* L)
{
	if (L->LeftChild != nullptr || L->RightChild != nullptr)
	{
		RLNTriversal(L->RightChild);
		RLNTriversal(L->LeftChild);
		cout << "\t\t";
		cout << L->Data << " ";
		if (L->Color == RED)
		{
			cout << "(" << "RED" << ")" << " ";
		}
		else
		{
			cout << "(" << "BLACK" << ")" << " ";
		}
		if (L->DuplicateCount > 0)
		{
			PrintDup(L->Data, L->DuplicateCount, L->Color);
		}
	}
	else
	{
		return;
	}
}
void RedBlackTree::LRNTriversal(TNode* L)
{
	
	if (L->LeftChild != nullptr || L->RightChild != nullptr)
	{
		LRNTriversal(L->LeftChild);
		LRNTriversal(L->RightChild);
		cout << "\t\t"; 
		cout << L->Data << " ";
		if (L->Color == RED)
		{
			cout << "(" << "RED" << ")" << " ";
		}
		else
		{
			cout << "(" << "BLACK" << ")" << " ";
		}
		if (L->DuplicateCount > 0)
		{
			PrintDup(L->Data, L->DuplicateCount, L->Color);
		}
	}
	else
	{
		return;
	}
}
void RedBlackTree::NLRTriversal(TNode* L)
{
	if (L->LeftChild != nullptr || L->RightChild != nullptr)
	{
		cout << "\t\t";
		cout << L->Data << " ";
		if (L->DuplicateCount > 0)
		{
			PrintDup(L->Data, L->DuplicateCount, L->Color);
		}
		NLRTriversal(L->LeftChild);
		NLRTriversal(L->RightChild);
	}
	else
	{
		return;
	}
}
void RedBlackTree::NRLTriversal(TNode* L)
{
	
	if (L->LeftChild != nullptr || L->RightChild != nullptr)
	{
		cout << "\t\t";
		cout << L->Data << " ";
		NRLTriversal(L->RightChild);
		NRLTriversal(L->LeftChild);
		if (L->DuplicateCount > 0)
		{
			PrintDup(L->Data, L->DuplicateCount, L->Color);
		}
	}
	else
	{
		return;
	}
}
void RedBlackTree::ReadTree(string FName)
{
	ifstream fin(FName);
	if (fin.is_open())
	{
		int val = 0;
		while (fin >> val)
		{
			this->Insert(val);
		}
		fin.close();
	}
	else
	{
		cout << "\t\t\t";
		cout << "File Error !" << endl;
	}
}
void RedBlackTree::RRotate(TNode* RT)
{
		TNode* Temp = RT->LeftChild;
		RT->LeftChild = Temp->RightChild;
		if (Temp->RightChild != NRoot) 
		{
			Temp->RightChild->Parent = RT;
		}
		Temp->Parent = RT->Parent;
		if (RT->Parent == nullptr) 
		{
			this->Root = Temp;
		}
		else 
		if (RT == RT->Parent->RightChild) 
		{
			RT->Parent->RightChild = Temp;
		}
		else 
		{
			RT->Parent->LeftChild = Temp;
		}
		Temp->RightChild = RT;
		RT->Parent = Temp;
}
void RedBlackTree::LRotate(TNode* RT)
{
	TNode* Temp = RT->RightChild;
	RT->RightChild = Temp->LeftChild;
	if (Temp->LeftChild != NRoot) 
	{
		Temp->LeftChild->Parent = RT;
	}
	Temp->Parent = RT->Parent;
	if (RT->Parent == nullptr) 
	{
		this->Root = Temp;
	}
	else 
	if (RT == RT->Parent->LeftChild) 
	{
		RT->Parent->LeftChild = Temp;
	}
	else 
	{
		RT->Parent->RightChild = Temp;
	}
	Temp->LeftChild = RT;
	RT->Parent = Temp;
}
TNode* RedBlackTree::SearchHelper(TNode* P,int Val)
{
	if (P == NRoot || Val == P->Data) 
	{
		return P;
	}
	if (Val > P->Data) 
	{
		return SearchHelper(P->RightChild, Val);
	}
	else
	{
		return SearchHelper(P->LeftChild, Val);
	}
}
TNode* RedBlackTree::SearchVal(int Val)
{
	return SearchHelper(Root, Val);
}
bool RedBlackTree::IsExist(int Val)
{
	if (SearchVal(Val) == NRoot)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void RedBlackTree::PrintDup(int val,int dup,NodeColor N)
{
	for (int i = 0; i < dup; i++)
	{
		cout << "\t\t";
		cout << val << "(";
		if (N == BLACK)
		{
			cout << "RED" << ")" << endl;
			N = RED;
		}
		else
		{
			cout << "BLACK" << ")" << endl;
			N = BLACK;
		}
	}
}
void RedBlackTree::Recoloring_Rotation(TNode*& Temp, TNode*& TR, bool RT)
{
	if (Temp->Color == RED)
	{
		Temp->Color = BLACK;
		TR->Parent->Color = BLACK;
		TR->Parent->Parent->Color = RED;
		TR = TR->Parent->Parent;
	}
	else
	{
		if (RT == true)
		{
			if (TR == TR->Parent->LeftChild)
			{
				TR = TR->Parent;
				RRotate(TR);
			}
			TR->Parent->Color = BLACK;
			TR->Parent->Parent->Color = RED;
			LRotate(TR->Parent->Parent);
		}
		else
		{
			if (TR == TR->Parent->RightChild)
			{
				TR = TR->Parent;
				LRotate(TR);
			}
			TR->Parent->Color = BLACK;
			TR->Parent->Parent->Color = RED;
			RRotate(TR->Parent->Parent);
		}
	}
}
void RedBlackTree::TreeBalancer(TNode* TR)
{
	TNode* Temp;
	while (TR->Parent->Color == RED) 
	{
		if (TR->Parent == TR->Parent->Parent->RightChild) 
		{
			Temp = TR->Parent->Parent->LeftChild;
			Recoloring_Rotation(Temp, TR, true);
		}
		else 
		{
			Temp = TR->Parent->Parent->RightChild;
			Recoloring_Rotation(Temp, TR, false);
		}
		if (TR == Root) 
		{
			break;
		}
	}
	Root->Color = BLACK;
}
void RedBlackTree::Insert(int Vs)
{
	if (IsExist(Vs) == true)
	{
		TNode* T = SearchHelper(Root,Vs);
		T->DuplicateCount++;
	}
	else
	{
		TNode* TN = new TNode;
		TN->Data = Vs;
		TN->LeftChild = NRoot;
		TN->RightChild = NRoot;
		TN->Color = RED;

		TNode* RT = nullptr;
		TNode* Temp = this->Root;

		while (Temp != NRoot)
		{
			RT = Temp;
			if (TN->Data < Temp->Data)
			{
				Temp = Temp->LeftChild;
			}
			else
			{
				Temp = Temp->RightChild;
			}
		}
		TN->Parent = RT;
		if (RT == nullptr)
		{
			Root = TN;
		}
		else if (TN->Data < RT->Data)
		{
			RT->LeftChild = TN;
		}
		else
		{
			RT->RightChild = TN;
		}

		if (TN->Parent == nullptr)
		{
			TN->Color = BLACK;
			return;
		}
		if (TN->Parent->Parent == nullptr)
		{
			return;
		}
		TreeBalancer(TN);
	}
}
void RedBlackTree::InOrder(bool LNR)
{
	if (LNR == true)
	{
		LNRTriversal(Root);
	}
	else
	{
		RNLTriversal(Root);
	}
}
void RedBlackTree::PostOrder(bool LRN)
{
	if (LRN == true)
	{
		LRNTriversal(Root);
	}
	else
	{
		RLNTriversal(Root);
	}
}
void RedBlackTree::PreOrder(bool NLR)
{
	if (NLR == true)
	{
		NLRTriversal(Root);
	}
	else
	{
		NRLTriversal(Root);
	}
}
void RedBlackTree::CopyTree(TNode*& root,TNode* T)
{
	if (T == NRoot)
	{
		root = NRoot;
	}
	else
	{
		root = new TNode(T->Data,T->Parent,T->Color,T->DuplicateCount);
		CopyTree(root->LeftChild, T->LeftChild);
		CopyTree(root->RightChild, T->RightChild);
	}

/*
	TNode* copyNode = nullptr;
	if (root != nullptr)
	{
		copyNode = new TNode;
		copyNode->Color = root->Color;
		copyNode->Data = root->Data;
		copyNode->DuplicateCount = root->DuplicateCount;
		copyNode->LeftChild = CopyTree(root->LeftChild);
		copyNode->RightChild = CopyTree(root->RightChild);	
	}
	return copyNode;*/
}
void RedBlackTree::DUPremove(TNode* P)
{
	if (P == NRoot)
	{
		return;
	}
	else
	{
		if (P->DuplicateCount > 0)
		{
			P->DuplicateCount = 0;
		}
		DUPremove(P->LeftChild);
		DUPremove(P->RightChild);
	}
}
void RedBlackTree::AllDupRemover()
{
	DUPremove(Root);
}
void RedBlackTree::DestroyTreeHelper(TNode* &DT)
{
	if (DT == NRoot)
	{
		return;
	}
	else
	{
		DestroyTreeHelper(DT->LeftChild);
		DestroyTreeHelper(DT->RightChild);
		delete DT;
	}
}
void RedBlackTree::DestroyAllNodes()
{
	DestroyTreeHelper(Root);
	Root = NRoot;
}
void RedBlackTree::ParentDisplay(int Val)
{
	if (Root->Data == Val)
	{
		cout << "\t\t\t";
		cout << Val << " not contain any Parent (ROOT NODE). "<< endl;
		return;
	}
	TNode* Temp = SearchHelper(Root, Val);
	if (Temp != NRoot)
	{
		cout << "\t\t\t";
		cout << Temp->Data << " has a Parent of " << Temp->Parent->Data << endl;
	}
	else
	{
		cout << "\t\t\t";
		cout << Temp->Data << " Does not Exist in Tree! " << endl;
	}
}
void RedBlackTree::DeleteNode(int Vs)
{
	DeleteCasesHelper(Root, Vs);
}
TNode* RedBlackTree::GetMin(TNode* N)
{
	while (N->LeftChild != NRoot) 
	{
		N = N->LeftChild;
	}
	return N;
}
void RedBlackTree::ChangeChild(TNode* S, TNode* V)
{
	if (S->Parent == nullptr) 
	{
		Root = V;
	}
	else if (S == S->Parent->LeftChild)
	{
		S->Parent->LeftChild = V;
	}
	else 
	{
		S->Parent->RightChild = V;
	}
	V->Parent = S->Parent;
}
void RedBlackTree::DeleteCasesHelper(TNode* P, int Vs)
{
	TNode* DelNode = NRoot;
	DelNode = SearchHelper(P, Vs);
	if (DelNode == NRoot)
	{
		cout << "\t\t\tNo such Value Exists!" << endl;
		return;
	}
	else
	{
		TNode* TR;
		TNode* TN = DelNode;
		NodeColor PrevColor = TN->Color;
		if (DelNode->LeftChild == NRoot)
		{
			TR = DelNode->RightChild;
			ChangeChild(DelNode, DelNode->RightChild);
		}
		else if (DelNode->RightChild == NRoot)
		{
			TR = DelNode->LeftChild;
			ChangeChild(DelNode, DelNode->LeftChild);
		}
		else
		{
			TN = GetMin(DelNode->RightChild);
			PrevColor = TN->Color;
			TR = TN->RightChild;
			if (TN->Parent == DelNode)
			{
				TR->Parent = TN;
			}
			else
			{
				ChangeChild(TN, TN->RightChild);
				TN->RightChild = DelNode->RightChild;
				TN->RightChild->Parent = TN;
			}

			ChangeChild(DelNode, TN);
			TN->LeftChild = DelNode->LeftChild;
			TN->LeftChild->Parent = TN;
			TN->Color = DelNode->Color;
		}
		delete DelNode;
		if (PrevColor == BLACK)
		{
			DeleteCaseSatifier(TR);
		}
	}
}
void RedBlackTree::Recolor_Rotate_Left(TNode*& TR, TNode*& UT)
{
	if (UT->Color == RED)
	{
		UT->Color = BLACK;
		TR->Parent->Color = RED;
		RRotate(TR->Parent);
		UT = TR->Parent->LeftChild;
	}

	if (UT->RightChild->Color == BLACK && UT->RightChild->Color == BLACK)
	{
		UT->Color = RED;
		TR = TR->Parent;
	}
	else
	{
		if (UT->LeftChild->Color == BLACK)
		{
			UT->RightChild->Color = BLACK;
			UT->Color = RED;
			LRotate(UT);
			UT = TR->Parent->LeftChild;
		}
		UT->Color = TR->Parent->Color;
		TR->Parent->Color = BLACK;
		UT->LeftChild->Color = BLACK;
		RRotate(TR->Parent);
		TR = Root;
	}
}
void RedBlackTree::Recolor_Rotate_Right(TNode*& TR, TNode*& UT)
{
	if (UT->Color == RED)
	{
		UT->Color = BLACK;
		TR->Parent->Color = RED;
		LRotate(TR->Parent);
		UT = TR->Parent->RightChild;
	}

	if (UT->LeftChild->Color == BLACK && UT->RightChild->Color == BLACK)
	{
		UT->Color = RED;
		TR = TR->Parent;
	}
	else
	{
		if (UT->RightChild->Color == BLACK)
		{
			UT->LeftChild->Color = BLACK;
			UT->Color = RED;
			RRotate(UT);
			UT = TR->Parent->RightChild;
		}
		UT->Color = TR->Parent->Color;
		TR->Parent->Color = BLACK;
		UT->RightChild->Color = BLACK;
		LRotate(TR->Parent);
		TR = Root;
	}
}
void RedBlackTree::DeleteCaseSatifier(TNode* TR)
{
	TNode* UT;
	while (TR != Root && TR->Color == BLACK)
	{
		if (TR == TR->Parent->LeftChild)
		{
			UT = TR->Parent->RightChild;
			Recolor_Rotate_Right(TR, UT);
		}
		else
		{
			UT = TR->Parent->LeftChild;
			Recolor_Rotate_Left(TR, UT);
		}
	}
	TR->Color = BLACK;
}
TNode* RedBlackTree::RG(TNode* P, int Val)
{
	if (P == NRoot || Val < P->Data)
	{
		return P;
	}
	if (Val > P->Data)
	{
		return RG(P->RightChild, Val);
	}
	else
	{
		return RG(P->LeftChild, Val);
	}
}
void RedBlackTree::DeleteGreaterVal(int Val)
{
	TNode* P = NRoot;
	while (true)
	{
		P = RG(Root, Val);
		if (P == NRoot)
		{
			break;
		}
		else
		{
			DeleteNode(P->Data);
		}
	}
}
RedBlackTree::~RedBlackTree()
{
	this->DestroyAllNodes();
	this->Root = nullptr;
}