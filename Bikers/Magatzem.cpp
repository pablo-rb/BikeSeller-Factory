#include "Magatzem.h"
#include "Empresa.h"
using namespace std;

Magatzem::Magatzem():Entitat("", "")
{
}

Magatzem::Magatzem(string nom, string codi):Entitat(nom, codi)
{
}

void Magatzem::enmagatzemarComanda(vector<Bicicleta*>& paquet, Data dataEntrada)
{
    for (int i = 0; i < paquet.size(); i++) 
    {
        paquet[i]->setCodiRus(Empresa::generaCodiRus(paquet[i]->getModel()));
        Empresa::afegeixSeguiment(paquet[i]);
        //CONSULTAR IMPLEMENTACION CREACION ENTIDAD
        Empresa::actualitzaEstat(paquet[i]->getCodiRus(), EstatBicicleta::EN_MAGATZEM, this);
        m_stock[paquet[i]->getModel()].push(paquet[i]);
    }
}


float Magatzem::procesQA(Comanda& c, vector<Bicicleta*>& paquet, Data dataActual)
{
    float preu = 0;
    if (c.getTotalBicicletes() == paquet.size() && dataActual <= c.getDataEntregaPrevista())
    {
        map<string, int> modBicis;
        for (int i = 0; i < paquet.size(); i++)
        {
            if (modBicis.count(paquet[i]->getModel()) == 0)
            {
                modBicis[paquet[i]->getModel()] = 0;
            }
            else
            {
                modBicis[paquet[i]->getModel()] = ++modBicis.find(paquet[i]->getModel())->second;
            }
        }
        vector <lineaComanda> comanda = c.getLlistaComanda();
        for (int i = 0; i < comanda.size(); i++)
        {
            if (comanda[i].m_quantitat != modBicis.find(comanda[i].m_model)->second)
            {
                preu -= (c.getCostTotal() * 0.1) + c.getCostTotal();
            }
        }
        preu = c.getCostTotal();
    }
    return preu;
}

bool Magatzem::rebreComanda(Comanda& c, vector<Bicicleta*>& paquet, Data dataRecepcioPaquet)
{
    enmagatzemarComanda(paquet, dataRecepcioPaquet);
    float preuCorregit;
    preuCorregit = procesQA(c, paquet, dataRecepcioPaquet);
    if ((c.getTotalBicicletes() == paquet.size()) && (dataRecepcioPaquet <= c.getDataEntregaPrevista()))
    {
        generaFactura(true, preuCorregit, c);
        return true;
    }
    else
    {
        generaFactura(false, preuCorregit, c);
        return false;
    }
}

//IMPRIME UNA FACTURA DE LAS BICIS DE LA COMANDA
void Magatzem::generaFactura(bool paquetComplet, float costCorregit, Comanda& c)
{
    ofstream fitxer;
    vector<lineaComanda> v = c.getLlistaComanda();
    fitxer.open("factura.txt");
    if (paquetComplet)
    {
        fitxer << "Resum comanda." << endl;
        fitxer << "Dades Entitat responsable:" << endl;
        fitxer << "Nom: " << m_nomEntitat << endl;
        fitxer << "Codi identificatiu: " << m_codiIdidentificatiu << endl;
        fitxer << "Articles." << endl;
        for (int i = 0; i < v.size(); i++)
        {
            fitxer << v[i].m_model << " * " << v[i].m_quantitat << endl;
            fitxer << endl;
        }
        fitxer << "Preu final: " << costCorregit << endl;
    }
    else
    {
        fitxer << "Resum comanda." << endl;
        fitxer << "Dades Entitat responsable:" << endl;
        fitxer << "Nom: " << m_nomEntitat << endl;
        fitxer << "Codi identificatiu: " << m_codiIdidentificatiu << endl;
        fitxer << "Articles." << endl;
        fitxer << "El paquet no pasa els test de qualitat." << endl;
        fitxer << "Es redueix el cost del paquet en un 1.1" << endl;
        fitxer << "Preu final: " << costCorregit << endl;
    }
    fitxer.close();
}

/*
*Para mostrar el catalogo hemos creado una priority_queue que funcione como una variable auxiliar
*Enseñamos el top() de la cola de nuestro map y luego para poder enseñar el siguiente valor hay que hacer
*un pop() de dicha cola. Por ese motivo creamos una cola auxiliar para finalmente volver a copiar la cola aux
*a la cola original sin perder valores
*/
void Magatzem::mostraCataleg()
{
    map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>::iterator it = m_stock.begin();
    for (it; it != m_stock.end(); it++)
    {
        cout << it->first << endl;
        priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta> q;
        while (!(it->second.empty()))
        {
            cout << it->second.top() << endl;
            q.push(it->second.top());
            it->second.pop();
        }
        it->second = q;
    }
}

//FUNCION QUE USAMOS PARA VACIAR EL STOCK DEL MAGATZEM
void Magatzem::vaciaStock(const string& s)
{
    m_stock[s].pop();
}