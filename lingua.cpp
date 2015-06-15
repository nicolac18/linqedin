#include "lingua.h"

Lingua::Lingua(string l): lingua(l) {}

// metodi getter
string Lingua::getLingua() const {
   return lingua;
}

// metodi writer
void Lingua::scrivi(QXmlStreamWriter& stream) const {
   stream.writeTextElement("lingua", QString::fromStdString(lingua));
}
