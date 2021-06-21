#include "BicicletaInfantil.h"

BicicletaInfantil::BicicletaInfantil(const BicicletaInfantil& inf)
{
	m_sModel = inf.getModel();
	m_sDescripcio = inf.getDescripcio();
	m_iTemporada = inf.getTemporada();
	m_oTalla = inf.getTalla();
	m_oQuadre = inf.getQuadre();
	m_oRoda = inf.getRoda();
	m_oFre = inf.getFre();
	m_oTipusBici = inf.getTipus();
	m_bPlegable = inf.m_bPlegable;
}

void BicicletaInfantil::setQuadre(const Quadre& quadre)
{
	if (quadre != Quadre::ALUMINI)
	{
		m_oQuadre = Quadre::ALUMINI;
	}
	else
	{
		m_oQuadre = quadre;
	}
}

void BicicletaInfantil::setFre(const Fre& fre)
{
	if (fre != Fre::RIM)
	{
		m_oFre = Fre::RIM;
	}
	else
	{
		m_oFre = Fre::RIM;
	}
}

void BicicletaInfantil::setRoda(const Roda& roda)
{
	if (roda != Roda::RODA_14 && roda != Roda::RODA_20)
	{
		m_oRoda = Roda::RODA_14;
	}
	else
	{
		m_oRoda = roda;
	}
}

void BicicletaInfantil::setTipus(const TipusBicicleta& tipus)
{
	if (tipus != TipusBicicleta::INFANTIL)
	{
		m_oTipusBici = TipusBicicleta::INFANTIL;
	}
	else
	{
		m_oTipusBici = tipus;
	}
}

BicicletaInfantil& BicicletaInfantil::operator=(const BicicletaInfantil& b)
{
	if (this != &b)
	{
		m_sModel = b.getModel();
		m_sDescripcio = b.getDescripcio();
		m_iTemporada = b.getTemporada();
		m_oTalla = b.getTalla();
		m_oQuadre = b.getQuadre();
		m_oRoda = b.getRoda();
		m_oFre = b.getFre();
		m_oTipusBici = b.getTipus();
		m_bPlegable = b.m_bPlegable;
	}
	return *this;
}

void BicicletaInfantil::mostra()
{
	Bicicleta::mostra();
	if (m_bPlegable)
		cout << "Plegable" << endl;
	else
		cout << "No Plegable" << endl;
}
