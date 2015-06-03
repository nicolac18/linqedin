#include "competenza.h"

Competenza::Competenza(string c):competenza(c) {}

string Competenza::getCompetenza() const {
   return competenza;
}


// metodi writer
void Competenza::scrivi(QXmlStreamWriter& stream) const {
   stream.writeTextElement("competenza", QString::fromStdString(competenza));
}
