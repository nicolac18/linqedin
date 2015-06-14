#ifndef QTFINESTRATITOLODISTUDIO_H
#define QTFINESTRATITOLODISTUDIO_H

#include "linqedinutente.h"
#include "titolodistudio.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QString>

class QtFinestraTitoloDiStudio: public QDialog {
   Q_OBJECT

private:
   LinQedInUtente& lUtente;

public:
   explicit QtFinestraTitoloDiStudio(LinQedInUtente&, QDialog* parent= 0);

   QGridLayout* layout;

   QLabel* labelTitolo;
   QLineEdit* lineEditTitolo;

   QLabel* labelSpecializzazione;
   QLineEdit* lineEditSpecializzazione;

   QPushButton* buttonInserisci;


public slots:
   void inserisci();
};

#endif // QTFINESTRATITOLODISTUDIO_H
