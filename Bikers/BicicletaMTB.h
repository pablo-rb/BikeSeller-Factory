#ifndef BICICLETAMTB_H
#define BICICLETAMTB_H

#include "Bicicleta.h"


enum class Categoria {
	RIGIDA = 0,
	DOBLE = 1,
};

enum class Modalitat {
	DESCENS = 0,
	ENDURO = 1,
	RALLY = 2,
	TRAIL = 3,
};

/**
* BicicletaMTB contine la inforacion relevante para definir una bicicleta MTB.
**/

class BicicletaMTB : public Bicicleta
{
public:
	BicicletaMTB(const string& model, string descripcio, const int& temporada, const Talla& talla, const Quadre& quadre, const Roda& roda, const Fre& fre, TipusBicicleta tipus, Categoria categoria, Modalitat modalitat, bool electrica) : Bicicleta(model, descripcio, temporada, talla, Quadre::ALUMINI, Roda::RODA_26, Fre::DISC, TipusBicicleta::MTB) { m_oCategoria = categoria;  m_oModalitat = modalitat; m_bElectrica = electrica; }
	BicicletaMTB(const BicicletaMTB& mtb);
	~BicicletaMTB() override {}

	Categoria getCategoria() const { return m_oCategoria; }
	Modalitat getModalitat() const { return m_oModalitat; }
	bool getElectrica() const { return m_bElectrica; }


	void setCategoria(const Categoria& categoria) { m_oCategoria = categoria; }
	void setModalitat(const Modalitat& modalitat) { m_oModalitat = modalitat; }
	void setElectrica(const bool& electrica) { m_bElectrica = electrica; }

	void setFre(const Fre& fre) override;
	void setRoda(const Roda& roda) override;
	void setTipus(const TipusBicicleta& tipus) override;


	BicicletaMTB& operator=(const BicicletaMTB& b);
	void mostra();

protected:
	ostream& format(ostream& os) const override { return os; }
private:
	Categoria m_oCategoria;
	Modalitat m_oModalitat;
	bool m_bElectrica;
};

#endif