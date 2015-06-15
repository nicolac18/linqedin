#include "esperienzaprofessionale.h"

EsperienzaProfessionale::EsperienzaProfessionale(QDate d, QDate a, string desc): dal(d), al(a), descrizione (desc) {}

// metodi getter
QDate EsperienzaProfessionale::getDal() const {
   return dal;
}

QDate EsperienzaProfessionale::getAl() const {
   return al;
}

string EsperienzaProfessionale::getDescrizione() const {
   return descrizione;
}

// metodi writer
void EsperienzaProfessionale::scrivi(QXmlStreamWriter& stream) const {
   stream.writeTextElement("dal", dal.toString("yyyy.MM.dd"));
   stream.writeTextElement("al", al.toString("yyyy.MM.dd"));
   stream.writeTextElement("descrizione", QString::fromStdString(descrizione));
}
