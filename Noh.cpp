#include "stdafx.h"
#include "Noh.h"


Noh::Noh()
{
}

Noh::Noh(int valor)
{
	this->valor = valor;
	this->esq = nullptr;
	this->dir = nullptr;
	this->peso = 0;
}


Noh::~Noh()
{
}

int Noh::getValor()
{
	return this->valor;
}

void Noh::setValor(int valor)
{
	this->valor = valor;
}

Noh * Noh::getEsq()
{
	return this->esq;
}

void Noh::setEsq(Noh * esq)
{
	this->esq = esq;
}

Noh * Noh::getDir()
{
	return this->dir;
}

void Noh::setDir(Noh * dir)
{
	this->dir = dir;
}
