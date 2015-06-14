#ifndef QTFINESTRAUTENTE_H
#define QTFINESTRAUTENTE_H

#include "linqedinutente.h"
#include "qtfinestracerca.h"
#include "qtfinestracompetenza.h"
#include "qtfinestraesperienzaprofessionale.h"
#include "qtfinestralingua.h"
#include "qtfinestratitolodistudio.h"
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
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextBrowser>
#include <QToolBox>


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
      QGridLayout* layoutTDiStudio;
      QGroupBox* gBoxTDiStudio;
      QTableWidget* tableTDiStudio;
      QPushButton* buttonAggiungiTDiStudio;
      QPushButton* buttonRimuoviTDiStudio;

      // lingue
      QGridLayout* layoutLingue;
      QGroupBox* gBoxLingue;
      QTableWidget* tableLingue;
      QPushButton* buttonAggiungiLingua;
      QPushButton* buttonRimuoviLingua;

      // competenze
      QGridLayout* layoutCompetenze;
      QGroupBox* gBoxCompetenze;
      QTableWidget* tableCompetenze;
      QPushButton* buttonAggiungiCompetenza;
      QPushButton* buttonRimuoviCompetenza;

      // esperienze professionali
      QGridLayout* layoutExpProfessionali;
      QGroupBox* gBoxExpProfessionali;
      QTableWidget* tableExpProfessionali;
      QPushButton* buttonAggiungiExpProfessionale;
      QPushButton* buttonRimuoviExpProfessionale;


   // groupBox rete di contatti
   QGroupBox* gBoxRete;
   QGridLayout* layoutRete;

      // rete di contatti
      QTableWidget* tableRete;
      QPushButton* buttonRimuoviRete;


   // groupBox bottoni
   QGroupBox* gBoxButton;
   QGridLayout* layoutButton;

      QPushButton* buttonSalva;
      QPushButton* buttonCerca;

private slots:
   void attivaSalva(QString);
   void attivaSalva(QDate);

public slots:
   void salva();
   void cerca();

   void aggiungiTDiStudio();
   void rimuoviTDiStudio();

   void aggiungiLingua();
   void rimuoviLingua();

   void aggiungiCompetenza();
   void rimuoviCompetenza();

   void aggiungiExpProfessionale();
   void rimuoviExpProfessionale();

   void rimuoviRete();

};

#endif // QTFINESTRAUTENTE_H
