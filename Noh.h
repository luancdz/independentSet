#pragma once
class Noh
{


public:
	Noh();
	Noh(int valor);
	~Noh();
	int getValor();
	void setValor(int valor);
	Noh* getEsq();
	void setEsq(Noh *esq);
	Noh* getDir();
	void setDir(Noh *dir);
	int valor;
	Noh *esq;
	Noh *dir;
	int peso;



};

