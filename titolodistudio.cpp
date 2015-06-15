#include "titolodistudio.h"

TitoloDiStudio::TitoloDiStudio(string t, string s): titolo(t), specializzazione(s) {}

TitoloDiStudio::~TitoloDiStudio() {}

string TitoloDiStudio::getTitolo() const {
   return titolo;
}

string TitoloDiStudio::getSpecializzazione() const {
   return specializzazione;
}

// metodi writer
void TitoloDiStudio::scrivi(QXmlStreamWriter& stream) const {
   stream.writeTextElement("titolo", "info");
   stream.writeTextElement("specializzazione", QString::fromStdString(specializzazione));
}
