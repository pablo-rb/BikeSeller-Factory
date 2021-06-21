#pragma once
#include <map>
#include <queue>
#include <string>
#include <fstream>
#include <cmath>
#include "Bicicleta.h"
#include "Comanda.h"
#include "Entitat.h"


/**
* La clase Magatzem gestiona el estoc de la empresa antes de ser enviado a tiendas.
* En el almacen se pasan controles de calidad para notificar a la empresa del estado en el que llega el pedido.
* El almacen tambien genera la factura final en funcion del estado con el que llega el pedido.
* 
**/

class Magatzem: public Entitat
{
public:
	Magatzem();
	Magatzem(string nom, string codi);
	~Magatzem() {}

	void enmagatzemarComanda(vector<Bicicleta*>& paquet, Data dataEntrada);
	float procesQA(Comanda& c, vector<Bicicleta*>& paquet, Data dataActual);
	bool rebreComanda(Comanda& c, vector<Bicicleta*>& paquet, Data dataRecepcioPaquet);
	void generaFactura(bool paquetComplet, float costCorregit, Comanda& c);
	Bicicleta* agafaBicicletaAntiga(const string& model);
	void mostraCataleg();

	string getNom() const { return m_nomEntitat; }
	void setNom(string nom) { m_nomEntitat = nom; }
	string getCodi() const { return m_codiIdidentificatiu; }
	void setCodi(string codi) { m_codiIdidentificatiu = codi; }
	void vaciaStock(const string& s);

	map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> getStock() const { return m_stock; }
	
private:
	map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> m_stock;
	float m_taxaEndarreriment = 1.1f;
};
