#pragma once

#include <string>
#include <iostream>
#include "Data.h"

using namespace std;


/**
* Enumeraciones necesarias para la creacion de bicicletas.
* Los valores son necesarios para poder realizar un control de errores eficiente.
* Si algun constructor recibe un parametro "ileagal" debeis establecer como valor por defecto
* el valor permitido mas peque�o del enum.
**/

//Indica el coste y que tipo de bici es a la vez
enum class TipusBicicleta
{
	INFANTIL = 100,
	MTB = 200,
	CARRETERA = 250
};

enum class Fre
{
	DISC = 0,
	RIM = 1,
};

enum class Quadre
{
	ALUMINI = 0,
	CARBONO = 1,
};

enum class Roda
{
	RODA_26 = 0,
	RODA_27 = 1,
	RODA_29 = 2,
	RODA_14 = 3,
	RODA_20 = 4,
	RODA_700 = 5,
};


enum class Talla
{
	XS = 0,
	S = 1,
	M = 2,
	L = 3,
	XL = 4,
};


/**
* Bicicleta es una clase que contiene toda la informacion relevante para definir una bicicleta generica.
*
**/
class Bicicleta
{
public:
	Bicicleta() { m_sModel = ""; m_sDescripcio = ""; m_iTemporada = 0; }
	Bicicleta(const string& model, string descripcio, const int& temporada, const Talla& talla, const Quadre& quadre, const Roda& roda, const Fre& fre, TipusBicicleta tipus) : m_sModel(model), m_sDescripcio(descripcio), m_iTemporada(temporada), m_oTalla(talla), m_oQuadre(quadre), m_oRoda(roda), m_oFre(fre), m_oTipusBici(tipus) {}
	Bicicleta(const Bicicleta& b);
	virtual ~Bicicleta() {}

	string getModel() const { return m_sModel; }
	string getDescripcio() const { return m_sDescripcio; }
	string getCodiRus() const { return m_sCodiRus; }
	int getTemporada() const { return m_iTemporada; }
	Talla getTalla() const { return m_oTalla; }
	Quadre getQuadre() const { return m_oQuadre; }
	Roda getRoda() const { return m_oRoda; }
	Fre getFre() const { return m_oFre; }
	TipusBicicleta getTipus() const { return m_oTipusBici; }
	Data getDataEntrada() const { return m_oDataEntrada; }

	virtual void setModel(const string& model) final { m_sModel = model; }
	virtual void setDescripcio(const string& descripcio) final { m_sDescripcio = descripcio; }
	virtual void setTemporada(const int& temporada) final { m_iTemporada = temporada; }
	virtual void setPreu(const TipusBicicleta& cost) { m_oTipusBici = cost; }
	virtual void setTalla(const Talla& talla) final { m_oTalla = talla; }

	virtual void setCodiRus(const string& codirus) final { m_sCodiRus = codirus; }

	virtual void setQuadre(const Quadre& quadre) { m_oQuadre = quadre; }
	virtual void setFre(const Fre& fre) { m_oFre = fre; }
	virtual void setRoda(const Roda& roda) { m_oRoda = roda; }

	virtual void setTipus(const TipusBicicleta& tipus) { m_oTipusBici = tipus; }

	void setDataEntrada(Data d) { m_oDataEntrada = d; }

	virtual float getPreu() const { return float(m_oTipusBici); }


	bool operator<(const Bicicleta& b1) const;
	Bicicleta& operator=(const Bicicleta& b);
	virtual void mostra();

protected:
	virtual ostream& format(ostream& os) const { return os; }

	string m_sModel; //MTB, Carretera, Infantil
	string m_sDescripcio; //año modelo
	int m_iTemporada;
	TipusBicicleta m_oTipusBici;
	Talla m_oTalla; //XS, S, M, L, XL

	string m_sCodiRus;

	Quadre m_oQuadre;
	Roda m_oRoda;
	Fre m_oFre;

	Data m_oDataEntrada;
	
};

struct CmpBicicleta {
	bool operator()(Bicicleta* a, Bicicleta* b) const
	{
		return b->getDataEntrada() < a->getDataEntrada();
	}
};