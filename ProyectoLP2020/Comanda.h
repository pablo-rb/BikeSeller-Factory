#pragma once
#include <vector>

#include "Bicicleta.h"
#include "Data.h"

/**
* Entrada que agrupa los datos de cada pedido. Contiene el tipo, la cantidad y el modelo.
**/
struct lineaComanda{
	TipusBicicleta tipus;
	int m_quantitat;
	string m_model;
};


 //Clase que almacena el pedido y los datos relacionados con el.
 //Una comanda debe de ser capaz de saber el totl de bicicletas pedidas, la fecha de entrega y el coste asociado a la misma.

class Comanda
{
public:
	Comanda(): m_iTotalBicis(0), m_fCostTotal(0) {}
	Comanda(const Data& entregaPrevista, vector<lineaComanda>& comanda);
	~Comanda() {}

	int getTotalBicicletes() const { return m_iTotalBicis; }
	Data getDataEntregaPrevista() const { return m_oEntregaPrevista; }
	float getCostTotal() const { return m_fCostTotal; }
	void setCostTotal(const float costTotal) { m_fCostTotal = costTotal; }
	vector<lineaComanda> getLlistaComanda() const { return m_comanda; }

private:
	vector<lineaComanda> m_comanda;
	Data m_oEntregaPrevista;
	int m_iTotalBicis;
	float m_fCostTotal;
};

