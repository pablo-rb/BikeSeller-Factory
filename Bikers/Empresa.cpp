#include "Empresa.h"

vector <string> Empresa::m_sCodiRus;
unordered_map<string, DadesSeguiment> Empresa::m_taulaSeguiment;

Empresa::Empresa(string name, int numBotigues, Magatzem* magatzemPrincipal, Proveidor& p): Entitat(m_nomEntitat, m_codiIdidentificatiu)
{
	m_oMagatzem = magatzemPrincipal;
	m_oProveidor = p;
	if (numBotigues > 0)
	{
		m_vBotiga.resize(numBotigues);
	}

	for (int i = 0; i < numBotigues; i++)
	{
		Botiga* b = new Botiga();
		m_vBotiga[i] = b;
	}
}


Empresa::Empresa(string name, vector<Botiga*> botigues, vector<Aresta> conexionsBotigues, Magatzem* magatzemPrincipal, Proveidor& p)
{
	m_nomEmpresa = name;
	m_oProveidor = p;
	m_oMagatzem = magatzemPrincipal;

	m_grafBotigues = Graf(botigues, conexionsBotigues);

	for (int i = 0; i < botigues.size(); i++)
	{
		botigues[i]->setMatgatzem(magatzemPrincipal);
		botigues[i]->getBotiguesProperes();
	}
	m_vBotiga = botigues;
}


bool Empresa::realitzaComanda(Comanda& c, Proveidor& p)
{
	return p.procesaComanda(c, m_oMagatzem);
}

string Empresa::generaCodiRus(const string& model)
{
    string codi = model + to_string(m_sCodiRus.size());
    m_sCodiRus.push_back(codi);
    return codi;
}

bool Empresa::realitzaComanda(Comanda& c)
{
    if (realitzaComanda(c, m_oProveidor))
    {
        return true;
    }
    return false;
}

int Empresa::getSeguentCodiRus()
{
    return m_sCodiRus.size();
}

//AÑADE UNA BICI AL REGISTRO SI NO ESTABA
bool Empresa::afegeixSeguiment(Bicicleta* bicicleta)
{
	if (bicicleta != NULL)
	{
		if (bicicleta->getCodiRus() != "")
		{
			unordered_map<string, DadesSeguiment>::iterator it = m_taulaSeguiment.find(bicicleta->getCodiRus());

			if (it == m_taulaSeguiment.end())
			{
				DadesSeguiment d;
				d.m_bicicleta = bicicleta;
				m_taulaSeguiment.emplace(bicicleta->getCodiRus(), d);
				return true;
			}
		}
	}
	return false;
}

//ACTUALIZA EN LA TABLA DE SEGUIMIENTO EL ESTADO EN QUE SE ENCUENTRAN LAS BICIS LAS CUALES IDENTIFICAMOS SEGUN SU CODIGO RUSO
bool Empresa::actualitzaEstat(const string& codiRus, EstatBicicleta nouEstat, Entitat* novaEntitat)
{
	if (m_taulaSeguiment[codiRus].m_bicicleta != NULL && novaEntitat != NULL)
	{
		m_taulaSeguiment[codiRus].m_historic.insert(m_taulaSeguiment[codiRus].m_historic.begin(), make_pair(nouEstat, novaEntitat));
		return true;
	}
    return false;
}

//DEVUELVE UN TRUE SI ALGUNA BICICLETA DE LA TABLA DE SEGUIMIENTO HA LLEGADO AL DESTINO FIJADO
bool Empresa::comprobaEstatCodi(string codiRus, EstatBicicleta objectiu)
{
	if (m_taulaSeguiment.count(codiRus) > 0)
	{
		bool flag = false;
		vector<pair<EstatBicicleta, Entitat*>> historial = m_taulaSeguiment[codiRus].m_historic;
		vector<pair<EstatBicicleta, Entitat*>>::iterator it = historial.begin();
		while (!flag && it != historial.end())
		{
			flag = (*it).first == objectiu;
			++it;
		}
		return flag;
	}
	return false;

}