#include "BicicletaCarretera.h"

BicicletaCarretera::BicicletaCarretera(const BicicletaCarretera& car)
{
	m_sModel = car.getModel();
	m_sDescripcio = car.getDescripcio();
	m_iTemporada = car.getTemporada();
	m_oTalla = car.getTalla();
	m_oQuadre = car.getQuadre();
	m_oRoda = car.getRoda();
	m_oFre = car.getFre();
	m_oTipusBici = car.getTipus();
	m_oModalitat = car.m_oModalitat;
	m_bElectrica = car.m_bElectrica;
}

void BicicletaCarretera::setRoda(const Roda& roda)
{
	if (roda != Roda::RODA_700)
	{
		m_oRoda = Roda::RODA_700;
	}
	else
	{
		m_oRoda = roda;
	}
}

void BicicletaCarretera::setTipus(const TipusBicicleta& tipus)
{
	if (tipus != TipusBicicleta::CARRETERA)
	{
		m_oTipusBici = TipusBicicleta::CARRETERA;
	}
	else
	{
		m_oTipusBici = tipus;
	}
}

BicicletaCarretera& BicicletaCarretera::operator=(const BicicletaCarretera& b)
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
		m_oModalitat = b.m_oModalitat;
		m_bElectrica = b.m_bElectrica;
	}
	return *this;
}

void BicicletaCarretera::mostra()
{
	Bicicleta::mostra();
	cout << float(m_oModalitat) << " ";
	if (m_bElectrica)
		cout << "Electrica" << endl;
	else
		cout << "No Electrica" << endl;
}
