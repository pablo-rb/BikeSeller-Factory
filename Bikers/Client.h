#pragma once
#include <vector>
#include <algorithm>
#include "Bicicleta.h"
#include "Botiga.h"
#include "Entitat.h"

class Client: public Entitat
{
public:
	Client() = default;
	Client(string nom, string dni);
	bool comprarBicicleta(string model, Botiga& b);
	vector<Bicicleta*>& getBicicletes() { return m_bicisComprades; }
	void setBicicletes(vector<Bicicleta*> bicis) { m_bicisComprades = bicis; }

private:
	int m_totalBicis;
	vector<Bicicleta*> m_bicisComprades;
};

