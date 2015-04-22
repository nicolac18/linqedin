#ifndef QTFINESTRAAMMINISTRATORE_H
#define QTFINESTRAAMMINISTRATORE_H

#include "databaselinqedin.h"
#include "iodatabase.h"
#include "linqedinamministratore.h"
#include "qtfinestraregistrazione.h"

#include <QComboBox>
#include <QDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QFileDialog>
//#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QStringList>
//#include <QTextBrowser>
#include <QToolBox>
#include <QVBoxLayout>

class QtFinestraAmministratore: public QDialog {
   Q_OBJECT

private:
   LinQedInAmministratore& lAmministratore;
   void aggiornaLista();

public:
   explicit QtFinestraAmministratore(LinQedInAmministratore&, QWidget* parent= 0);

   QGridLayout* layout;

   // groupBox operazioni utente
   QGroupBox* gBoxUtente;
   QGridLayout* layoutUtente;

      // inserisci
      QPushButton* buttonInserisci;

      QToolBox* tBox;

      // cerca
      QGridLayout* layoutCerca;
      QGroupBox* gBoxCerca;

      QLabel* labelCercaId;
      QLineEdit* lineEditCercaId;

      QLabel* labelCercaNome;
      QLineEdit* lineEditCercaNome;
      QLabel* labelCercaCognome;
      QLineEdit* lineEditCercaCognome;

      QPushButton* buttonCerca;

      // cambia tipo
      QVBoxLayout* layoutCambiaTipo;
      QGroupBox* gBoxCambiaTipo;

      QLineEdit* lineEditCambiaTipo;
      QComboBox* comboBoxCambiaTipo;
      QPushButton* buttonCambiaTipo;

      // rimuovi
      QLineEdit* lineEditRimuoviId;

      QVBoxLayout* layoutRimuovi;
      QGroupBox* gBoxRimuovi;

      QPushButton* buttonRimuovi;

      // list widget
      QListWidget* listWidget;


   // groupBox operazioni database
   QGroupBox* gBoxDatabase;
   QVBoxLayout* layoutDatabase;

      // bottoni database
      QPushButton* buttonCaricaDB;
      QPushButton* buttonSalvaDB;


signals:

private slots:
   void inserisciID(QListWidgetItem*);
   void resetCampi(int);

public slots:
   void apriQtFinestraRegistrazione();

   void cercaUtente();
   void cambiaTipoUtente();
   void rimuoviUtente();

   void caricaDatabase();
   void salvaDatabase();

};

#endif // QTFINESTRAAMMINISTRATORE_H
