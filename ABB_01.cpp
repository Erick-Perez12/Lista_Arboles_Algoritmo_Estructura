#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct TreeNode{
     int data;
     struct TreeNode *izq, *der;
};

typedef struct TreeNode *raiz;

raiz crearNodo(int x)
{
     raiz newNodo = new(struct TreeNode);
     newNodo->data = x;
     newNodo->izq = NULL;
     newNodo->der = NULL;

     return newNodo;
}
void insertar(raiz &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->data)
          insertar(arbol->izq, x);
     else if(x > arbol->data)
          insertar(arbol->der, x);
}

void PreOrder(raiz arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->data <<" ";
          PreOrder(arbol->izq);
          PreOrder(arbol->der);
     }
}

void InOrder(raiz arbol)
{
     if(arbol!=NULL)
     {
          InOrder(arbol->izq);
          cout << arbol->data << " ";
          InOrder(arbol->der);
     }
}

void PostOrder(raiz arbol)
{
     if(arbol!=NULL)
     {
          PostOrder(arbol->izq);
          PostOrder(arbol->der);
          cout << arbol->data << " ";
     }
}

void verArbol(raiz arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->data <<endl;
     verArbol(arbol->izq, n+1);
}

raiz unirraiz(raiz izq, raiz der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    raiz centro = unirraiz(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

void remove(raiz &arbol, int x)
{
     if(arbol==NULL) return;

     if(x<arbol->data)
         remove(arbol->izq, x);
     else if(x>arbol->data)
         remove(arbol->der, x);

     else
     {
         raiz p = arbol;
         arbol = unirraiz(arbol->izq, arbol->der);
         delete p;
     }
}

int height(raiz arbol)
{
    int AltI, AltD;

    if(arbol==NULL)
        return -1;
    else
    {
        AltI = height(arbol->izq);
        AltD = height(arbol->der);

        if(AltI>AltD)
            return AltI+1;
        else
            return AltD+1;
    }
}
void PreorderITE(TreeNode *raiz)
{
	stack<TreeNode*> S ;
	TreeNode * aux=raiz;
	while ( aux != NULL || ! S.empty ( )){
		if( aux!= NULL ){
			S.push (aux ); // S . push ( root );
			cout<<aux->data<<" ";
			aux = aux->izq ;
			
		} else {
			
			aux = S.top();
			S.pop(); // root = S . pop ();
			aux = aux->der ;
		}
	}
}

void InorderITE(TreeNode *raiz)
{
	stack<TreeNode*> S ;
	TreeNode * aux=raiz;
	while ( aux != NULL || ! S.empty ( )){
		if( aux!= NULL ){
			S.push (aux ); 
			aux = aux->izq ;
		} else {
			aux = S.top();
			S.pop(); 
			cout<<aux->data<<" ";
			aux = aux->der ;
		}
	}
}

void PostorderITE(TreeNode *raiz)
{
	if (raiz == NULL)
        return;
    stack<TreeNode *> s1, s2;
    s1.push(raiz);
    TreeNode* aux=raiz;
 
    while (!s1.empty()) {
        aux = s1.top();
        s1.pop();
        s2.push(aux);
 
        if (aux->izq)
            s1.push(aux->izq);
        if (aux->der)
            s1.push(aux->der);
    }
    while (!s2.empty()) {
        aux = s2.top();
        s2.pop();
        cout << aux->data << " ";
    }
}

int main(){
    raiz arbol = NULL;   
    insertar(arbol, 4);
	insertar(arbol, 8);
	insertar(arbol, 2);
	insertar(arbol, 9);
	insertar(arbol, 3);
	insertar(arbol, 6);
	insertar(arbol, 1);
	insertar(arbol, 7);
	
	cout << "RECURSIVO";
    cout << "\n PreOrden:  ";   PreOrder(arbol);
    cout << "\n InOrden:  ";   InOrder(arbol);
    cout << "\n PostOrden:  ";   PostOrder(arbol);

 	cout << "\nITERATIVO";
    cout << "\n PreOrden:  ";   PreorderITE(arbol);
    cout << "\n InOrden:  ";   InorderITE(arbol);
    cout << "\n PostOrden:  ";   PostorderITE(arbol);
    cout << "\n Mostrando Arbol \n\n";
	verArbol( arbol, 0);
	remove(arbol,3);
    cout << "\n Mostrando Arbol \n\n";
    verArbol( arbol, 0);
}
