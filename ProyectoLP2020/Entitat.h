#pragma once
#include <string>

using namespace std;

class Entitat
{
public:
	string getNom() const { return m_nomEntitat; }
	string getCodi() const { return m_codiIdidentificatiu; }
	void setNom(string nom) { m_nomEntitat = nom; }
	void setCodi(string codi) { m_codiIdidentificatiu = codi; }

protected:
	Entitat() : m_nomEntitat(""), m_codiIdidentificatiu("") {}
	Entitat(string nom, string codiIdentificatiu) { m_nomEntitat = nom; m_codiIdidentificatiu = codiIdentificatiu; }

	string m_nomEntitat;
	string m_codiIdidentificatiu;
};

