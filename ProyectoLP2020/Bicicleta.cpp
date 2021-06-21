#include "Bicicleta.h"

Bicicleta::Bicicleta(const Bicicleta& b)
{
    m_sModel = b.m_sModel;
    m_sDescripcio = b.m_sDescripcio;
    m_oTalla = b.m_oTalla;
    m_oTipusBici = b.m_oTipusBici;
    m_sCodiRus = b.m_sCodiRus;
    m_iTemporada = b.m_iTemporada;
    m_oDataEntrada = b.m_oDataEntrada;
    m_oQuadre = b.m_oQuadre;
    m_oRoda = b.m_oRoda;
    m_oFre = b.m_oFre;
}

bool Bicicleta::operator<(const Bicicleta& b1) const
{
    return (m_oDataEntrada < b1.m_oDataEntrada);
}

Bicicleta& Bicicleta::operator=(const Bicicleta& b)
{
    if (this != &b)
    {
        m_sModel = b.m_sModel;
        m_sDescripcio = b.m_sDescripcio;
        m_oTalla = b.m_oTalla;
        m_oTipusBici = b.m_oTipusBici;
        m_sCodiRus = b.m_sCodiRus;
        m_iTemporada = b.m_iTemporada;
        m_oDataEntrada = b.m_oDataEntrada;
        m_oQuadre = b.m_oQuadre;
        m_oRoda = b.m_oRoda;
        m_oFre = b.m_oFre;
    }
    return *this;
}

void Bicicleta::mostra()
{
    cout << m_sModel << " " << m_sDescripcio << " " << m_iTemporada << " " << float(m_oTipusBici) << " " << float(m_oTalla) << " " << float(m_oQuadre) << " " << float(m_oRoda) << " " << float(m_oFre) << " ";
}
