#ifndef QTFINESTRAAMMINISTRATORE_H
#define QTFINESTRAAMMINISTRATORE_H

#include "databaselinqedin.h"
#include "iodatabase.h"
#include "linqedinamministratore.h"
#include "qtfinestraregistrazione.h"
#include "qtfinestrautentevisualizzazione.h"

#include <QComboBox>
#include <QDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QFileDialog>
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QStringList>
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
      QPushButton* buttonVisualizza;

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
      QPushButton* buttonReset;

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

private slots:
   void inserisciID(QListWidgetItem*);
   void resetCampi(int);

public slots:
   void aggiornaListaS();

   void apriQtFinestraRegistrazione();
   void apriQtFinestraVisualizza();

   void cercaUtente();
   void cambiaTipoUtente();
   void rimuoviUtente();

   void caricaDatabase();
   void salvaDatabase();

};

#endif // QTFINESTRAAMMINISTRATORE_H
