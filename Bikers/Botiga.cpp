#include "Botiga.h"
#include "Empresa.h"

bool Botiga::solicitaComanda(const Comanda& c, Magatzem& m)
{
    vector<lineaComanda> comandaVirtual = c.getLlistaComanda();
    map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> stockVirtual = m.getStock();

    for (int i = 0; i < comandaVirtual.size(); i++)
    {
        if ((stockVirtual[comandaVirtual[i].m_model].size() == 0) || (stockVirtual[comandaVirtual[i].m_model].size() < comandaVirtual[i].m_quantitat)) // si se cumple quiere decir que en el 
        // almacen no hay las suficientes para llenar la comanda por tanto retornamos false
        {
            return false;
        }
        else
        {
            for (int j = 0; j < comandaVirtual[i].m_quantitat; j++)
            {
                m_stockBotiga[comandaVirtual[i].m_model].push(stockVirtual[comandaVirtual[i].m_model].top());
                m.vaciaStock(comandaVirtual[i].m_model);
            }
        }
    }
    return true;
}

bool Botiga::solicitaComanda(Comanda& c)
{
    bool trobat = false;
    if (getMagatzem() != NULL)
    {
        vector<lineaComanda> comandaVirtual = c.getLlistaComanda();
        map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> m_stockMagatzem = m_magatzem->getStock();
        for (int i = 0; i < comandaVirtual.size(); i++)
        {
            // si se cumple quiere decir que en el 
            // almacen no hay las suficientes para llenar la comanda por tanto retornamos false
            if ((m_stockMagatzem[comandaVirtual[i].m_model].size() == 0) || (m_stockMagatzem[comandaVirtual[i].m_model].size() < comandaVirtual[i].m_quantitat))
            {
                for (int j = 0; j < m_stockMagatzem[comandaVirtual[i].m_model].size(); j++)
                {
                    m_stockBotiga[comandaVirtual[i].m_model].push(m_stockMagatzem[comandaVirtual[i].m_model].top());
                    Empresa::actualitzaEstat(m_stockBotiga[comandaVirtual[i].m_model].top()->getCodiRus(), EstatBicicleta::EN_BOTIGA, this);
                    m_magatzem->vaciaStock(comandaVirtual[i].m_model);
                }
                trobat = false;
            }
            else
            {
                for (int j = 0; j < comandaVirtual[i].m_quantitat; j++)
                {
                    m_stockBotiga[comandaVirtual[i].m_model].push(m_stockMagatzem[comandaVirtual[i].m_model].top());
                    Empresa::actualitzaEstat(m_stockBotiga[comandaVirtual[i].m_model].top()->getCodiRus(), EstatBicicleta::EN_BOTIGA, this);
                    m_magatzem->vaciaStock(comandaVirtual[i].m_model);
                }
                trobat = true;
            }
        }
    }
    return trobat;
}

void Botiga::mostraCataleg()
{
    map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>::iterator it = m_stockBotiga.begin();
    for (it; it != m_stockBotiga.end(); it++)
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

int Botiga::calculaStockTotal()
{
    int contador = m_stockBotiga["INF_A"].size() + m_stockBotiga["MTB_A"].size();

    return contador;
}

void Botiga::setMatgatzem(Magatzem* m)
{
    m_magatzem = m;
}

void Botiga::setveinesOrdenades(vector<Botiga*> veines)
{
    m_botiguesVeines = veines;
}

bool Botiga::solicitaBicicletaAMagatzem(const string& model, Bicicleta*& bicicleta)
{
    //Mirmaos con el find si existe este modelo en el almacen
    map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> stockMagatzem = m_magatzem->getStock();
    map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>::iterator it = stockMagatzem.find(model);
    if (it != stockMagatzem.end() && stockMagatzem[model].size() > 0)
    {
        bicicleta = stockMagatzem.find(model)->second.top();
        m_magatzem->vaciaStock(model);
        return true;
    }
    return false;
}


bool Botiga::procesa_venda(const string& model, Bicicleta*& bicicleta)
{
    if (comprobaBicicletaEnStock(model, bicicleta))
    {
       return true;
    }
    else
        if (ComprobaStockEnVeines(model, bicicleta))
        {
            return true;
        }
        else
            if (solicitaBicicletaAMagatzem(model, bicicleta))
            {
                return true;
            }
            else
            {
                return false;
            }
    return false;
}


bool Botiga::comprobaBicicletaEnStock(const string& model, Bicicleta*& bicicleta)
{
    bool trobat = false;

    map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>::iterator it = m_stockBotiga.find(model);
    if(it != m_stockBotiga.end())
    {
        bicicleta = m_stockBotiga.find(model)->second.top();
        m_stockBotiga.find(model)->second.pop();
        trobat = true;
    }

    return trobat;
}

bool Botiga::ComprobaStockEnVeines(const string& model, Bicicleta*& bicicleta)
{
    bool trobat = false;
    int i = 0;
    map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>::iterator it;

    //Inicializamos la búsqueda del modelo en las tiendas cercanas
    while (!trobat && i < m_botiguesVeines.size())
    {
        trobat = m_botiguesVeines[i]->comprobaBicicletaEnStock(model, bicicleta);
        i++;
    }
    return trobat;
}