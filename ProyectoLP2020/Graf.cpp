#include "Graf.h"

Graf::Graf()
{
	m_iNumNodes = 0;
	m_iNumArestes = 0;
}

Graf::Graf(vector<Botiga*> llistaVertexs, vector<Aresta> llistaArestes)
{
	m_iNumNodes = llistaVertexs.size();
	m_iNumArestes = llistaArestes.size();

	for (int i = 0; i < m_iNumNodes; ++i)
	{
		Node* n = new Node(llistaVertexs[i]);
		m_nodesGraf.push_back(n);
	}
	creaMatriu(llistaArestes);
}

vector<Node*> Graf::getVertexs() const
{
	return m_nodesGraf;
}

vector<vector<int>> Graf::getArestes() const
{
	return m_matriuAdj;
}

vector<Botiga*> Graf::getBotiguesOrdenades(Node* nodeInici)
{
	//RESETEAMOS LOS NODOS 
	for (int i = 0; i < m_iNumNodes; ++i)
	{
		m_nodesGraf[i]->distanciaMinima = INT_MAX;
		m_nodesGraf[i]->visitat = false;
	}

	m_botiguesOrdenades.resize(0, NULL);
	aux.resize(0, NULL);

	m_nodesGraf = dijkstra(nodeInici);

	//FUNCION QUE ORDENA LAS TIENDAS DE DISTANCIA MINIMA MENOR A DISTANCIA MINIMO MAYOR
	ordenar(aux);

	for (int j = 0; j < aux.size(); ++j)
	{
		m_botiguesOrdenades.push_back(aux[j]->botiga);
	}

	return m_botiguesOrdenades;
}

Graf& Graf::operator=(Graf g)
{
	if (this != &g)
	{
		m_iNumArestes = g.m_iNumArestes;
		m_iNumNodes = g.m_iNumNodes;
		m_nodesGraf = g.m_nodesGraf;
		m_matriuAdj = g.m_matriuAdj;
	}
	return *this;
}

int Graf::getPes(Node* inici, Node* desti)
{
	return m_matriuAdj[getIndex(inici)][getIndex(desti)];
}

int Graf::getIndex(Node* vertex)
{
	vector<Node*>::iterator it = find(m_nodesGraf.begin(), m_nodesGraf.end(), vertex);
	return distance(m_nodesGraf.begin(), it);
}

Node* Graf::distanciaMinima()
{
	int min = INT_MAX;
	int minIndex = -1;

	for (int posVei = 0; posVei < m_iNumNodes; ++posVei)
	{
		if (!m_nodesGraf[posVei]->visitat && m_nodesGraf[posVei]->distanciaMinima <= min)
		{
			min = m_nodesGraf[posVei]->distanciaMinima;
			minIndex = posVei;
		}
	}
	Node* aux = m_nodesGraf[minIndex];
	return aux;
}


//GUARDAMOS SI SE VISITA Y LA DIST MINIMA EN EL NODE PUESTO QUE ES UN STRUCT
vector<Node*> Graf::dijkstra(Node* nodeInici)
{
	m_nodesGraf[getIndex(nodeInici)]->distanciaMinima = 0;
	for (int i = 0; i < m_iNumNodes - 1; ++i)
	{
		Node* posVeiAct = distanciaMinima();
		int posVeiActIndex = getIndex(posVeiAct);

		m_nodesGraf[posVeiActIndex]->visitat = true;
		for (int posVei = 0; posVei < m_iNumNodes; ++posVei)
		{
			if (!m_nodesGraf[posVei]->visitat)
			{
				if (m_matriuAdj[posVeiActIndex][posVei] != -1)
				{
					if (m_nodesGraf[posVeiActIndex]->distanciaMinima + m_matriuAdj[posVeiActIndex][posVei] < m_nodesGraf[posVei]->distanciaMinima)
					{
						m_nodesGraf[posVei]->distanciaMinima = m_nodesGraf[posVeiActIndex]->distanciaMinima + m_matriuAdj[posVeiActIndex][posVei];
						aux.push_back(m_nodesGraf[posVei]);
					}
				}
			}
		}
	}
	return m_nodesGraf;
}

void Graf::creaMatriu(const vector<Aresta>& llistaArestes)
{
	m_matriuAdj.resize(m_iNumNodes);
	for (int i = 0; i < m_iNumNodes; ++i)
	{
		m_matriuAdj[i].resize(m_iNumNodes, -1);
	}
	for (int i = 0; i < llistaArestes.size(); ++i)
	{
		m_matriuAdj[llistaArestes[i].inici][llistaArestes[i].desti] = llistaArestes[i].pes;
		m_matriuAdj[llistaArestes[i].desti][llistaArestes[i].inici] = llistaArestes[i].pes;
	}
}

void Graf::ordenar(vector<Node*>& v)
{
	for (int i = 0; i < m_iNumNodes - 1; ++i)
	{
		for (int j = 0; j < m_iNumNodes-2; ++j)
		{
			if (aux[j]->distanciaMinima > aux[j + 1]->distanciaMinima)
				swap(aux[j], aux[j+1]);
		}
	}
}
