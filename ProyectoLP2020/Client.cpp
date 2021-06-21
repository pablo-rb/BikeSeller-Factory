#include "Client.h"
#include "Empresa.h"
#include "Bicicleta.h"

Client::Client(string nom, string dni) :Entitat(nom, dni)
{
	m_totalBicis = 0;
	m_bicisComprades.resize(m_totalBicis);
}

bool Client::comprarBicicleta(string model, Botiga& b)
{
	Bicicleta* bici = new Bicicleta();
	bool trobat = b.procesa_venda(model, bici);
	if (trobat)
	{
		m_bicisComprades.push_back(bici);
		trobat = Empresa::actualitzaEstat(bici->getCodiRus(), EstatBicicleta::VENUDA, this);
		return trobat;
	}
	return false;
}