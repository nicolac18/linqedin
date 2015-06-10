#ifndef QTFINESTRAUTENTEVISUALIZZAZIONE_H
#define QTFINESTRAUTENTEVISUALIZZAZIONE_H

#include "linqedinutente.h"
#include "utente.h"

#include <QDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QString>
//#include <QTextBrowser>
#include <QTreeWidget>
#include <QTreeWidgetItem>

class QtFinestraUtenteVisualizzazione: public QDialog {
   Q_OBJECT

private:
   LinQedInUtente& lUtente;

   void riempiTreeInfo();
   void riempiTextRete();

public:
   explicit QtFinestraUtenteVisualizzazione(LinQedInUtente&,  QWidget* parent = 0);

   QHBoxLayout* layout;

   // info principali
   QGroupBox* gBoxInfo;
   QGridLayout* layoutInfo;

      // idUtente
      QGridLayout* layoutIdUtente;
      QGroupBox* gBoxIdUtente;

      QLabel* labelIdUtente;
      QLineEdit* lineEditIdUtente;
      QLabel* labelPassword;
      QLineEdit* lineEditPassword;

      // profilo
      QGridLayout* layoutProfilo;
      QGroupBox* gBoxProfilo;

      QLabel* labelNome;
      QLineEdit* lineEditNome;
      QLabel* labelCognome;
      QLineEdit* lineEditCognome;
      QLabel* labelDataDiNascita;
      QLineEdit* lineEditDataDiNascita;
      QLabel* labelEmailDue;
      QLineEdit* lineEditEmailDue;

      // profilo
      QGridLayout* layoutTipologia;
      QGroupBox* gBoxTipologia;

      QLabel* labelTipologia;
      QLineEdit* lineEditTipologia;

      // altre info
      QTreeWidget* treeInfo;

   // groupBox rete di contatti
   QGroupBox* gBoxRete;
   QVBoxLayout* layoutRete;

      // rete di contatti
      QListWidget* textRete;

signals:

public slots:

};

#endif // QTFINESTRAUTENTEVISUALIZZAZIONE_H
