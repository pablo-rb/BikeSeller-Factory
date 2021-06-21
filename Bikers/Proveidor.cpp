#include "Proveidor.h"
#include "utils.h"
#include "BicicletaInfantil.h"


Proveidor::Proveidor(const int& codiProveidor)
{
    m_codiProveidor = codiProveidor;
}

Data Proveidor::generaDataEnviament(Data dataprevista, int diesmaxim)
{
    return (dataprevista + diesmaxim);
}

bool Proveidor::procesaComanda(Comanda c, Magatzem* m)
{
    //Queremos conseguir separar la comanda y a partir de la lineaComanda crear las diferentes bicis.
    vector<lineaComanda> m_comanda = c.getLlistaComanda();
    for (int i = 0; i < m_comanda.size(); i++) {
            switch (m_comanda[i].tipus) {
                case TipusBicicleta::INFANTIL:
                    for (int j = 0; j < m_comanda[i].m_quantitat; j++)
                    {
                        Bicicleta* b = new BicicletaInfantil(m_comanda[i].m_model, "", randomAnyModel(), randomTalla(), randomQuadre(), randomRoda(), randomFre(), m_comanda[i].tipus, randomBool());
                        m_paquet.push_back(b);
                    }
                    break;
                case TipusBicicleta::CARRETERA:
                    for (int j = 0; j < m_comanda[i].m_quantitat; j++)
                    {
                        Bicicleta* b = new BicicletaCarretera(m_comanda[i].m_model, "", randomAnyModel(), randomTalla(), randomQuadre(), randomRoda(), randomFre(), m_comanda[i].tipus, randomModalitatC(), randomBool());
                        m_paquet.push_back(b);
                    }
                    break;
                case TipusBicicleta::MTB:
                    for (int j = 0; j < m_comanda[i].m_quantitat; j++)
                    {
                        Bicicleta* b = new BicicletaMTB(m_comanda[i].m_model, "", randomAnyModel(), randomTalla(), randomQuadre(), randomRoda(), randomFre(), m_comanda[i].tipus, randomCategoria(), randomModalitat(), randomBool());
                        m_paquet.push_back(b);
                    }
                    break;
                default:
                    break;
            }
    }
    bool recepcioCorrecta;
    recepcioCorrecta = m->rebreComanda(c, m_paquet, generaDataEnviament(c.getDataEntregaPrevista(), randomDiesMaxim()));
    return recepcioCorrecta;
}

void Proveidor::setCodiProveidor(const int& proveidor)
{
    m_codiProveidor = proveidor;
}

int Proveidor::getCodiProveidor() const
{
    return m_codiProveidor;
}