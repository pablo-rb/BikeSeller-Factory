#pragma once
#include <string>

#include "Botiga.h"
#include "Comanda.h"
#include "Magatzem.h"
#include "Proveidor.h"
#include "Graf.h"
#include <unordered_map>
/**
 *
* La clase empresa aglutina la inforamcion para gestionar la comunicacion del almacen con el proveedor, asi como las tiendas.
* La empresa se define por un conjunto de tiendas, un almacen y un proveedor.
* La empresa realizar� pedidos al provedor y recibira una notificacion indicando si el pedido ha llegado correctamente a almacen.
* 
**/

enum class EstatBicicleta {
	EN_MAGATZEM,
	EN_BOTIGA,
	VENUDA,
	RETORNADA
};

struct DadesSeguiment {
	Bicicleta* m_bicicleta;
	vector<pair<EstatBicicleta, Entitat*>> m_historic;
	DadesSeguiment() {
		m_bicicleta = nullptr;
		m_historic = vector<pair<EstatBicicleta, Entitat*>>();
	}
};


class Empresa: public Entitat
{
public:
	Empresa(string name, int numBotigues, Magatzem* magatzemPrincipal, Proveidor& p);
	Empresa(string name, vector<Botiga*> botigues, vector<Aresta> conexionsBotigues, Magatzem* magatzemPrincipal, Proveidor& p);
	
	string getName() const { return m_nomEmpresa; }
	Magatzem* getMagatzem() { return m_oMagatzem; }
	vector<Botiga*>& getBotigues() { return m_vBotiga; }
	void setProveidor(Proveidor& proveidor) { m_oProveidor = proveidor; }
	Proveidor& getProveidor() { return m_oProveidor; }
	void afegeixBotiga(Botiga* b) { m_vBotiga.push_back(b); }
	int getSeguentCodiRus();

	bool realitzaComanda(Comanda& c, Proveidor& p);
	static string generaCodiRus(const string& model);

	bool realitzaComanda(Comanda& c);

	//Añade una bici al registro si no esta
	static bool afegeixSeguiment(Bicicleta* bicicleta);

	//Actualiza el estado del historico
	static bool actualitzaEstat(const string& codiRus, EstatBicicleta nouEstat, Entitat* novaEntitat);

	//Comprueba si ha llegado a destino
	static bool comprobaEstatCodi(string codiRus, EstatBicicleta objectiu);

private:
	string m_nomEmpresa;
	int m_iNumBotigues;

	Magatzem* m_oMagatzem;
	Proveidor m_oProveidor;

	vector<Botiga*> m_vBotiga;
	Graf m_grafBotigues;

	static vector<string> m_sCodiRus;
	static unordered_map<string, DadesSeguiment> m_taulaSeguiment;
};
