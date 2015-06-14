#ifndef QTFINESTRACERCA_H
#define QTFINESTRACERCA_H

#include "linqedinutente.h"
#include "utente.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QTextBrowser>

class QtFinestraCerca: public QDialog {
   Q_OBJECT

private:
   LinQedInUtente& lUtente;
   string id;
   QList<QString> list;

   void riempiTextBrowser();

public:
   explicit QtFinestraCerca(LinQedInUtente&, QWidget *parent = 0);

   QGridLayout* layout;

   QLabel* labelNome;
   QLineEdit* lineEditNome;

   QLabel* labelCognome;
   QLineEdit* lineEditCognome;

   QTextBrowser* textBrowserCerca;

   QPushButton* buttonCerca;
   QPushButton* buttonAggiungi;
   QPushButton* buttonEsci;

public slots:
   void aggiungi();
   void cerca();
   void esci();

private slots:

};

#endif // QTFINESTRACERCA_H
