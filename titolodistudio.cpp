#include "titolodistudio.h"

TitoloDiStudio::TitoloDiStudio(string t, string s): titolo(t), specializzazione(s) {}

TitoloDiStudio::~TitoloDiStudio() {}

string TitoloDiStudio::getTitolo() const {
   return titolo;
}

string TitoloDiStudio::getSpecializzazione() const {
   return specializzazione;
}
