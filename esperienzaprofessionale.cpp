#include "esperienzaprofessionale.h"

EsperienzaProfessionale::EsperienzaProfessionale(QDate d, QDate a, string desc): dal(d), al(a), descrizione (desc) {}

string EsperienzaProfessionale::getAl() const {
   return al.toString().toStdString();
}

string EsperienzaProfessionale::getDal() const {
   return dal.toString().toStdString();
}

string EsperienzaProfessionale::getDescrizione() const {
   return descrizione;
}
