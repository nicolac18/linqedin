#ifndef QTFINESTRALOGIN_H
#define QTFINESTRALOGIN_H

#include "databaselinqedin.h"
#include "linqedinamministratore.h"
#include "linqedinutente.h"
#include "qtfinestraamministratore.h"
#include "qtfinestrautente.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QString>

class QtFinestraLogin: public QDialog {
   Q_OBJECT

private:
   DatabaseLinQedIn* db;
   bool utente;

   void apriQtFinestra(Utente&);

public:
   explicit QtFinestraLogin(bool, DatabaseLinQedIn*, QDialog *parent = 0);

   QGridLayout* layout;

   QLabel* labelTitolo;

   QLabel* labelNomeUtente;
   QLineEdit* lineEditNomeUtente;

   QPushButton* buttonLogin;

   QPushButton* buttonEsci;

signals:

public slots:
   void login();
   void esci();
};

#endif // QTFINESTRALOGIN_H
