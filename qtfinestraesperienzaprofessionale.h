#ifndef QTFINESTRAESPERIENZAPROFESSIONALE_H
#define QTFINESTRAESPERIENZAPROFESSIONALE_H

#include "linqedinutente.h"
#include "esperienzaprofessionale.h"

#include <QDateEdit>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QString>

class QtFinestraEsperienzaProfessionale: public QDialog {
   Q_OBJECT

private:
   LinQedInUtente& lUtente;

public:
   explicit QtFinestraEsperienzaProfessionale(LinQedInUtente&, QDialog* parent= 0);

   QGridLayout* layout;

   QLabel* labelDal;
   QDateEdit* dateEditDal;

   QLabel* labelAl;
   QDateEdit* dateEditAl;

   QLabel* labelDescrizione;
   QLineEdit* lineEditDescrizione;

   QPushButton* buttonInserisci;

public slots:
   void inserisci();
};

#endif // QTFINESTRAESPERIENZAPROFESSIONALE_H
