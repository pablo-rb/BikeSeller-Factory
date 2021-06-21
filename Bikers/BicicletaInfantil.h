#ifndef BICICLETAINFANTIL_H
#define BICICLETAINFANTIL_H

#include "Bicicleta.h"

/**
* BicicletaInfantil contine la inforacion relenavte para definir una bicicleta infantil.
*
**/
class BicicletaInfantil : public Bicicleta
{
public:
	BicicletaInfantil(const string& model, string descripcio, const int& temporada, const Talla& talla, const Quadre& quadre, const Roda& roda, const Fre& fre, TipusBicicleta tipus, const bool& plegable): Bicicleta(model, descripcio, temporada, talla, Quadre::ALUMINI, Roda::RODA_14, Fre::RIM, TipusBicicleta::INFANTIL) { m_bPlegable = plegable; }
	BicicletaInfantil(const BicicletaInfantil& inf);
	~BicicletaInfantil() override {}

	bool getPlegable() const { return m_bPlegable; }

	void setPlegable(const bool& plegable) { m_bPlegable = plegable; }

	void setQuadre(const Quadre& quadre) override;
	void setFre(const Fre& fre) override;
	void setRoda(const Roda& roda) override;
	void setTipus(const TipusBicicleta& tipus) override;

	BicicletaInfantil& operator=(const BicicletaInfantil& b);
	void mostra();

protected:
	ostream& format(ostream& os) const override { return os; }
private:
	bool m_bPlegable;
};

#endif