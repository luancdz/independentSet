// independentSetArvore.cpp : Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include "Noh.h"
#include <iostream>
#include "Grafo.h"


int max(int x, int y);
void grafo(vector<Grafo> grafo);
int maiorConjIndep(Noh* raiz);
int otimizado(Noh* raiz);
bool verificaVizinhos(Grafo grafo, vector<char> lista);
using namespace std;
int main()
{
	//Exemplo para demonstrar
	Noh *raiz = new Noh(10);
	raiz->esq = new Noh(20);
	raiz->dir = new Noh(30);
	raiz->esq->esq = new Noh(40);
	raiz->esq->dir = new Noh(50);
	raiz->dir->dir = new Noh(60);
	raiz->esq->dir->dir = new Noh(14);
	raiz->esq->dir->esq = new Noh(10);

	/*
	raiz->dir->esq = new Noh(10);
	raiz->esq->dir->esq = new Noh(10);
	raiz->esq->dir->dir= new Noh(14);
	raiz->esq->esq->esq = new Noh(10);
	raiz->esq->esq->dir = new Noh(14);
	raiz->dir->dir->esq = new Noh(10);
	raiz->dir->dir->dir = new Noh(14);
	raiz->dir->esq->esq = new Noh(10);
	raiz->dir->esq->dir = new Noh(14);
	//raiz->dir = new Noh(22);
	//raiz->dir->dir = new Noh(25);
	*/
	cout <<"Tamanho do maior conjunto independente eh:  " << otimizado(raiz) << endl;


	// Exemplo desenho 1
	/*Grafo A;
	A.valor = 'A';
	A.ligados.push_back('B');
	A.ligados.push_back('E');
	A.ligados.push_back('F');

	Grafo B;
	B.valor = 'B';
	B.ligados.push_back('D');
	B.ligados.push_back('C');
	B.ligados.push_back('A');


	Grafo D;
	D.valor = 'D';
	D.ligados.push_back('B');
	D.ligados.push_back('C');
	D.ligados.push_back('E');

	Grafo C;
	C.valor = 'C';
	C.ligados.push_back('D');
	C.ligados.push_back('B');
	C.ligados.push_back('F');
	//C.ligados.push_back('Z');

	Grafo D;
	D.valor = 'D';
	D.ligados.push_back('B');
	D.ligados.push_back('C');
	D.ligados.push_back('E');

	Grafo E;
	E.valor = 'E';
	E.ligados.push_back('A');
	E.ligados.push_back('F');
	E.ligados.push_back('D');

	Grafo F;
	F.valor = 'F';
	F.ligados.push_back('A');
	F.ligados.push_back('C');
	F.ligados.push_back('E');

	// Exemplo desenho 2
	/*Grafo A;
	A.valor = 'A';
	A.ligados.push_back('B');
	A.ligados.push_back('F');

	Grafo B;
	B.valor = 'B';
	B.ligados.push_back('A');
	B.ligados.push_back('C');

	Grafo C;
	C.valor = 'C';
	C.ligados.push_back('B');
	C.ligados.push_back('D');

	Grafo D;
	D.valor = 'D';
	D.ligados.push_back('E');
	D.ligados.push_back('C');

	Grafo E;
	E.valor = 'E';
	E.ligados.push_back('D');
	E.ligados.push_back('F');

	Grafo F;
	F.valor = 'F';
	F.ligados.push_back('A');
	F.ligados.push_back('E');
*/
	/*vector<Grafo> lista;
	lista.push_back(A);
	lista.push_back(B);
	lista.push_back(C);
	lista.push_back(D);
	lista.push_back(F);
	lista.push_back(E);

	grafo(lista);

	*/

	system("pause");
    return 0;
}

int maiorConjIndep(Noh *raiz) {
	if (raiz == NULL) {
		return 0;
	}

	int tamanho_excl = maiorConjIndep(raiz->esq) + maiorConjIndep(raiz->dir);

	int tamanho_incl = 1;

	if (raiz->esq) {
		tamanho_incl += maiorConjIndep(raiz->esq->esq) + maiorConjIndep(raiz->esq->dir);
	}
	if (raiz->dir) {
		tamanho_incl += maiorConjIndep(raiz->dir->esq) + maiorConjIndep(raiz->dir->dir);
	}

	return max(tamanho_excl, tamanho_incl);
}

int otimizado(Noh *raiz) {
	if (raiz == NULL)
		return 0;

	if (raiz->peso)
		return raiz->peso;

	if (raiz->esq == NULL && raiz->dir == NULL)
		return (raiz->peso = 1);

	// Calculate size excluding the current node
	int peso_excl = otimizado(raiz->esq) + otimizado(raiz->dir);

	// Calculate size including the current node
	int peso_incl = 1;
	if (raiz->esq)
		peso_incl += otimizado(raiz->esq->esq) + otimizado(raiz->esq->dir);
	if (raiz->dir)
		peso_incl += otimizado(raiz->dir->esq) + otimizado(raiz->dir->dir);

	// Maximum of two sizes is peso, store it for future uses.
	raiz->peso = max(peso_incl, peso_excl);

	return raiz->peso;
}

int max(int x, int y) {
	return (x > y) ? x : y;
}


void grafo(vector<Grafo> listaGrafo) {
	if (listaGrafo.empty()) {
		cout << "Grafo Vazio" << endl;
		return;
	}
	vector <char> listaSub;

	for (int i = 0; i < listaGrafo.size(); i++) {
		if (verificaVizinhos(listaGrafo[i], listaSub)) {
			listaSub.push_back(listaGrafo[i].valor);
		}
	}

	cout << "Valores do subconjunto são: ";
	for (int i = 0; i < listaSub.size(); i++) {
		cout << listaSub[i] << " ";
	}

}

bool verificaVizinhos(Grafo grafo, vector<char> lista) {
	for (int i = 0; i < grafo.ligados.size(); i++) {
		for (int j = 0; j < lista.size(); j++) {
			if (grafo.ligados[i] == lista[j]) {
				return false;
				break;
			}
		}
	}
	return true;
}