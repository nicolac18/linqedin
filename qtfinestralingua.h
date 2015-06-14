#ifndef QTFINESTRALINGUA_H
#define QTFINESTRALINGUA_H

#include "linqedinutente.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QString>

class QtFinestraLingua: public QDialog {
   Q_OBJECT

private:
   LinQedInUtente& lUtente;

public:
   explicit QtFinestraLingua(LinQedInUtente&, QDialog* parent= 0);

   QGridLayout* layout;

   QLabel* labelLingua;
   QLineEdit* lineEditLingua;

   QPushButton* buttonInserisci;

public slots:
   void inserisci();
};

#endif // QTFINESTRALINGUA_H
