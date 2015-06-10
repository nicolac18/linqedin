#ifndef QTFINESTRAREGISTRAZIONE_H
#define QTFINESTRAREGISTRAZIONE_H

#include "databaselinqedin.h"
#include "iodatabase.h"
#include "utenteexecutive.h"

#include <QDateEdit>
#include <QDialog>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QString>

class QtFinestraRegistrazione: public QDialog {
   Q_OBJECT

private:
   DatabaseLinQedIn* db;

public:
   explicit QtFinestraRegistrazione(DatabaseLinQedIn* db, QDialog *parent = 0);

   QGridLayout* layout;

   QLabel* labelEmail;
   QLineEdit* lineEditEmail;

   QLabel* labelNome;
   QLineEdit* lineEditNome;

   QLabel* labelCognome;
   QLineEdit* lineEditCognome;

   QLabel* labelDataDiNascita;
   QDateEdit* dateEditDataDiNascita;

   QLabel* labelTipoUtente;
   QComboBox* comboBoxTipoUtente;

   QPushButton* buttonRegistrati;

   QPushButton* buttonEsci;

signals:

public slots:
   void registrazione();
   void esci();

};

#endif // QTFINESTRAREGISTRAZIONE_H
