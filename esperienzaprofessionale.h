#ifndef ESPERIENZAPROFESSIONALE_H
#define ESPERIENZAPROFESSIONALE_H

#include <iostream>
#include <QDate>

using namespace std;

class EsperienzaProfessionale {
private:
   QDate dal;
   QDate al;
   string descrizione;

public:
   EsperienzaProfessionale(QDate, QDate, string);

   string getDal() const;
   string getAl() const;
   string getDescrizione() const;
};

#endif // ESPERIENZAPROFESSIONALE_H
