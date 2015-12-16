#include <iostream>
#define lambda NULL
using namespace std;
typedef int elementtype;

struct element {
       elementtype e;
       element *left, *right, *parent;
};
typedef element *node;
typedef node tree;

void Init(tree &T, elementtype x){
     element *p=new element;
     p->left=lambda;
     p->right=lambda;
     p->parent=lambda;
     p->e=x;
     T=p;
     }
     
element CreateLeftChild(tree &T,node n,elementtype x){
        element *p=new element;
        if(n->left != lambda) cout << "Veæ ima lijevo dijete!" << endl;
        else
		{     
             p->parent = n;
             
			 n->left=p;
             
			 p->left=lambda;
             p->right=lambda;
             p->e=x;
        }
        return *p;
        }

element CreateRightChild(tree &T,node n,elementtype x){
        element *p=new element;
        if( n->right != lambda )
                     cout << "Vec ima desno dijete!" << endl;
        else{
             
             p->parent = n;
             n->right=p;
             p->left=lambda;
             p->right=lambda;
             p->e=x;
             }
        return *p;
        }
        

void Delete(tree &T, node n){
    if( n->parent->left != lambda || n->parent->right != lambda){
    	cout << "Cvor nije list!" << endl;
	}
	else
	{
          if(n == n->parent->left) n->parent->left=lambda;
          else n->parent->right=lambda;
    }
    delete n;
}
     
void ChangeLabel(tree &T,node n, elementtype x){n->e=x;}
node Parent(tree &T, node n){return n->parent;}
node LeftChild(tree &T, node n){return n->left;} 
node RightChild(tree &T, node n){return n->right;}
node Root(tree &T){return T;}
elementtype Label(tree &T, node n){return n->e;}
