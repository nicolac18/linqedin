#ifndef QTFINESTRACOMPETENZA_H
#define QTFINESTRACOMPETENZA_H

#include "linqedinutente.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QString>

class QtFinestraCompetenza: public QDialog {
   Q_OBJECT

private:
   LinQedInUtente& lUtente;

public:
   explicit QtFinestraCompetenza(LinQedInUtente&, QDialog* parent= 0);

   QGridLayout* layout;

   QLabel* labelCompetenza;
   QLineEdit* lineEditCompetenza;

   QPushButton* buttonInserisci;

public slots:
   void inserisci();
};

#endif // QTFINESTRACOMPETENZA_H
