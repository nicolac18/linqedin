#ifndef QTFINESTRAPRINCIPALE_H
#define QTFINESTRAPRINCIPALE_H

#include "databaselinqedin.h"
#include "qtfinestralogin.h"
#include "qtfinestraregistrazione.h"

#include <QDialog>
#include <QGroupBox>
#include <QLabel>
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

   QPushButton* buttonRegistrati;
   QPushButton* buttonAccedi;
   QPushButton* buttonAmministratore;
   QPushButton* buttonEsci;

signals:

public slots:
   void apriQtFinestraLoginUtente();
   void apriQtFinestraLoginAmministratore();
   void apriQtFinestraRegistrazione();
   void esci();

};

#endif // QTFINESTRAPRINCIPALE_H
