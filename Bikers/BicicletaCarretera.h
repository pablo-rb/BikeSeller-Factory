#ifndef BICICLETACARRETERA_H
#define BICICLETACARRETERA_H

#include "Bicicleta.h"

enum class ModalitatC {
	AERO,
	GRANFONDO,
	GRAVEL,
	RENDIMIENTO,
};

/**
* BicicletaCarretera contine la inforacion relenavte para definir una bicicleta de carretera.
*
**/
class BicicletaCarretera : public Bicicleta
{
public:
	BicicletaCarretera(const string& model, string descripcio, const int& temporada, const Talla& talla, const Quadre& quadre, const Roda& roda, const Fre& fre, TipusBicicleta tipus, ModalitatC modalitat, bool electrica): Bicicleta(model, descripcio, temporada, talla, Quadre::ALUMINI, Roda::RODA_700, Fre::DISC, TipusBicicleta::CARRETERA) { m_oModalitat = modalitat; m_bElectrica = electrica; }
	BicicletaCarretera(const BicicletaCarretera& car);
	~BicicletaCarretera() override {}

	ModalitatC getModalitat() const { return m_oModalitat; }
	bool getElectrica() const { return m_bElectrica; }

	void setElectricaC(const bool& electrica) { m_bElectrica = electrica; }
	void setModalitat(const ModalitatC& modalitat) { m_oModalitat = modalitat; }

	void setRoda(const Roda& roda) override;
	void setTipus(const TipusBicicleta& tipus) override;

	BicicletaCarretera& operator=(const BicicletaCarretera& b);
	void mostra();


protected:
	ostream& format(ostream& os) const override { return os; }
private:
	ModalitatC m_oModalitat;
	bool m_bElectrica;
};

#endif