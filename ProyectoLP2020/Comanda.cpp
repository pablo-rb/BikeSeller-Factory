#include "Comanda.h"

Comanda::Comanda(const Data& entregaPrevista, vector<lineaComanda>& comanda)
{
	
	m_iTotalBicis = 0;
	for (int i = 0; i < comanda.size(); i++)
	{
		m_iTotalBicis += comanda[i].m_quantitat;
	}

	m_fCostTotal = getCostTotal();
	m_comanda = comanda;
	m_oEntregaPrevista = entregaPrevista;
}
