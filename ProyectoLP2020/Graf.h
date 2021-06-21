#pragma once
#include <limits.h>
#include "Botiga.h"
#include <algorithm>
using namespace std;

struct Node
{
	bool visitat;
	Botiga* botiga;
	int distanciaMinima;
	Node(Botiga* b) :visitat(false), botiga(b), distanciaMinima(INT_MAX) {}
};


struct Aresta
{
	int inici, desti, pes;
};

class Graf
{
public:
	Graf();
	Graf(vector<Botiga*> llistaVertexs, vector<Aresta> llistaArestes);
	vector<Node*> getVertexs() const;
	vector<vector<int>> getArestes() const;

	//DEVUELVE UN VECTOR DE BOTIGUES ORDENADAS SEGUN LA PROXIMIDAD DESDE UNA BOTIGA A LAS DEMÁS
	vector<Botiga*> getBotiguesOrdenades(Node* nodeInici);
	Graf& operator=(Graf g);


private:
	const int ARESTA_NULA = -1;

	int getPes(Node* inici, Node* desti);
	int getIndex(Node* vertex);
	Node* distanciaMinima();
	vector<Node*> dijkstra(Node* nodeInici);

	//ATRIBUTS
	int m_iNumNodes;
	int m_iNumArestes;
	vector<Node*> m_nodesGraf;
	vector<vector<int>> m_matriuAdj;

	//VECTOR DE BOTIGUES ORDENADES
	vector<Botiga*> m_botiguesOrdenades;

	//VECTOR AUXILIAR QUE USAMOS PARA ORDENAR EL VECTOR DE NODOS QUE CORRESPONDEN A LAS BOTIGAS CERCANAS
	vector<Node*> aux;

	//CREA LA LLISTA ADJACENCIA DE LA MATRIU A PARTIR D'UN LLISTA D'ARESTES
	void creaMatriu(const vector<Aresta>& llistaArestes);

	//ALGORITMO BURBUJA QUE ORDENA NODOS SEGUN LA DISTANCIA MINIMA
	void ordenar(vector<Node*>& v);
};
