#ifndef QTFINESTRAPRINCIPALE_H
#define QTFINESTRAPRINCIPALE_H

#include "databaselinqedin.h"
#include "linqedinamministratore.h"
#include "linqedinutente.h"
#include "qtfinestraamministratore.h"
#include "qtfinestraregistrazione.h"
#include "qtfinestrautente.h"

#include <QDialog>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>

class QtFinestraPrincipale: public QDialog {
   Q_OBJECT

private:
   DatabaseLinQedIn* db;

public:
   explicit QtFinestraPrincipale(QDialog* parent= 0);

   QVBoxLayout* layout;

   QLabel* labelTitolo;

   QVBoxLayout* layoutUtente;
   QGroupBox* gBoxUtente;

   QVBoxLayout* layoutAmministratore;
   QGroupBox* gBoxAmministratore;

   QLineEdit* lineEditNomeUtente;
   QPushButton* buttonAccedi;

   QPushButton* buttonRegistrati;

   QPushButton* buttonAmministratore;

   QPushButton* buttonEsci;

public slots:
   void apriQtFinestraUtente();
   void apriQtFinestraAmministratore();
   void apriQtFinestraRegistrazione();
   void esci();

};

#endif // QTFINESTRAPRINCIPALE_H
