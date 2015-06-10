#ifndef QTFINESTRAUTENTE_H
#define QTFINESTRAUTENTE_H

//#include "databaselinqedin.h"
#include "linqedinutente.h"
#include "utente.h"

#include <QComboBox>
#include <QDateEdit>
#include <QDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextBrowser>
#include <QToolBox>
#include <QVBoxLayout>


class QtFinestraUtente: public QDialog {
   Q_OBJECT

private:
   LinQedInUtente& lUtente;
   QStringList header;

   void riempiTableTDiStudio();
   void riempiTableLingue();
   void riempiTableCompetenze();
   void riempiTableExpProfessionali();

   void riempiTableRete();

   void aggiungiRiga();
   void rimuoviRiga();


public:
   explicit QtFinestraUtente(LinQedInUtente&,  QWidget* parent = 0);

   QHBoxLayout* layout;

   // groupBox info
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
      QDateEdit* dateEditDataDiNascita;
      QLabel* labelEmailDue;
      QLineEdit* lineEditEmailDue;

      // profilo
      QGridLayout* layoutTipologia;
      QGroupBox* gBoxTipologia;

      QLabel* labelTipologia;
      QLineEdit* lineEditTipologia;

      // tDiStudio
      QVBoxLayout* layoutTDiStudio;
      QGroupBox* gBoxTDiStudio;
      QTableWidget* tableTDiStudio;

      // lingue
      QVBoxLayout* layoutLingue;
      QGroupBox* gBoxLingue;
      QTableWidget* tableLingue;

      // competenze
      QVBoxLayout* layoutCompetenze;
      QGroupBox* gBoxCompetenze;
      QTableWidget* tableCompetenze;

      // esperienze professionali
      QVBoxLayout* layoutExpProfessionali;
      QGroupBox* gBoxExpProfessionali;
      QTableWidget* tableExpProfessionali;


   // groupBox rete di contatti
   QGroupBox* gBoxRete;
   QVBoxLayout* layoutRete;

      // rete di contatti
      QTableWidget* tableRete;
      QPushButton* buttonAggiungiRete;


   // groupBox bottoni
   QGroupBox* gBoxButton;
   QGridLayout* layoutButton;

      QPushButton* buttonSalva;
      QPushButton* buttonAggiungi;
      QPushButton* buttonRimuovi;


signals:

private slots:
   void attivaSalva(QString);
   void attivaSalva(QDate);

public slots:
   void salva();
   void aggiungiRete();

};

#endif // QTFINESTRAUTENTE_H
