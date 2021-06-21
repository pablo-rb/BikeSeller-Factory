#include "BicicletaMTB.h"

BicicletaMTB::BicicletaMTB(const BicicletaMTB& mtb)
{
	m_sModel = mtb.getModel();
	m_sDescripcio = mtb.getDescripcio();
	m_iTemporada = mtb.getTemporada();
	m_oTalla = mtb.getTalla();
	m_oQuadre = mtb.getQuadre();
	m_oRoda = mtb.getRoda();
	m_oFre = mtb.getFre();
	m_oTipusBici = mtb.getTipus();
	m_oCategoria = mtb.m_oCategoria;
	m_oModalitat = mtb.m_oModalitat;
	m_bElectrica = mtb.m_bElectrica;
}

void BicicletaMTB::setFre(const Fre& fre)
{
	if (fre != Fre::DISC)
	{
		m_oFre = Fre::DISC;
	}
	else
	{
		m_oFre = Fre::DISC;
	}
}

void BicicletaMTB::setRoda(const Roda& roda)
{
	if (roda != Roda::RODA_26 && roda != Roda::RODA_27 && roda != Roda::RODA_29)
	{
		m_oRoda = Roda::RODA_26;
	}
	else
	{
		m_oRoda = roda;
	}
}

void BicicletaMTB::setTipus(const TipusBicicleta& tipus)
{
	if (tipus != TipusBicicleta::MTB)
	{
		m_oTipusBici = TipusBicicleta::MTB;
	}
	else
	{
		m_oTipusBici = tipus;
	}
}

BicicletaMTB& BicicletaMTB::operator=(const BicicletaMTB& b)
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
		m_oCategoria = b.m_oCategoria;
		m_oModalitat = b.m_oModalitat;
		m_bElectrica = b.m_bElectrica;
	}
	return *this;
}

void BicicletaMTB::mostra()
{
	Bicicleta::mostra();
	cout << float(m_oCategoria) << " " << float(m_oModalitat) << " ";
	if (m_bElectrica)
		cout << "Electrica" << endl;
	else
		cout << "No Electrica" << endl;
}

