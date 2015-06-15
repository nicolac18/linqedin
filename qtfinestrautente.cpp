#include "qtfinestrautente.h"

QtFinestraUtente::QtFinestraUtente(LinQedInUtente& u, QWidget *parent): QDialog(parent), lUtente(u) {

   this->setWindowTitle("LinQedIn Utente");
   this->setMinimumSize(800, 700);

   layout= new QHBoxLayout(this);

   // groupBox info
   gBoxInfo= new QGroupBox("Informazioni", this);
   layoutInfo= new QGridLayout();

      // idUtente
      gBoxIdUtente= new QGroupBox("Id Utente", this);
      layoutIdUtente= new QGridLayout();

      labelIdUtente= new QLabel("IdUtente (email):");
      layoutIdUtente->addWidget(labelIdUtente, 0, 0, 1, 1);
      lineEditIdUtente= new QLineEdit(QString::fromStdString(lUtente.getUtente().getId()));
      lineEditIdUtente->setMinimumWidth(150);
      layoutIdUtente->addWidget(lineEditIdUtente, 0, 1, 1, 1);

      labelPassword= new QLabel("Password:");
      layoutIdUtente->addWidget(labelPassword, 1, 0, 1, 1);
      lineEditPassword= new QLineEdit(); lineEditPassword->setDisabled(true);
      layoutIdUtente->addWidget(lineEditPassword, 1, 1, 1, 1);

      gBoxIdUtente->setLayout(layoutIdUtente);

      layoutInfo->addWidget(gBoxIdUtente, 0, 0, 1, 2);


      // profilo
      gBoxProfilo= new QGroupBox("Profilo", this);
      layoutProfilo= new QGridLayout();

      labelNome= new QLabel("Nome:");
      layoutProfilo->addWidget(labelNome, 0, 0, 1, 1);
      lineEditNome= new QLineEdit(QString::fromStdString(lUtente.getUtente().getProfilo().getNome()));
         lineEditIdUtente->home(true); lineEditIdUtente->setReadOnly(true);
      layoutProfilo->addWidget(lineEditNome, 0, 1, 1, 1);

      labelCognome= new QLabel("Cognome:");
      layoutProfilo->addWidget(labelCognome, 1, 0, 1, 1);
      lineEditCognome= new QLineEdit(QString::fromStdString(lUtente.getUtente().getProfilo().getCognome()));
      layoutProfilo->addWidget(lineEditCognome, 1, 1, 1, 1);

      labelDataDiNascita= new QLabel("Data di nascita:");
      layoutProfilo->addWidget(labelDataDiNascita, 2, 0, 1, 1);
      dateEditDataDiNascita= new QDateEdit(this);
      dateEditDataDiNascita->setDisplayFormat("dd.MM.yyyy");
      dateEditDataDiNascita->setMinimumDate(QDate(1,1,1900)); dateEditDataDiNascita->setMaximumDate(QDate(1,1,2015));
      dateEditDataDiNascita->setDate(lUtente.getUtente().getProfilo().getDataDiNascita());
      layoutProfilo->addWidget(dateEditDataDiNascita, 2, 1, 1, 1);

      labelEmailDue= new QLabel("Email secondaria:");
      layoutProfilo->addWidget(labelEmailDue, 3, 0, 1, 1);
      lineEditEmailDue= new QLineEdit(QString::fromStdString(lUtente.getUtente().getProfilo().getEmailSecondaria()));
      layoutProfilo->addWidget(lineEditEmailDue, 3, 1, 1, 1);

      gBoxProfilo->setLayout(layoutProfilo);

      layoutInfo->addWidget(gBoxProfilo, 1, 0, 1, 2);


      // tipologia
      gBoxTipologia= new QGroupBox("Tipologia", this);
      layoutTipologia= new QGridLayout();

      labelTipologia= new QLabel("Tipologia:");
      layoutTipologia->addWidget(labelTipologia, 0, 0, 1, 1);

      lineEditTipologia= new QLineEdit(QString::fromStdString(lUtente.getUtente().getTipo())); lineEditTipologia->setReadOnly(true);

      layoutTipologia->addWidget(lineEditTipologia, 0, 1, 1, 1);

      gBoxTipologia->setLayout(layoutTipologia);

      layoutInfo->addWidget(gBoxTipologia, 2, 0, 1, 2);


      buttonSalva= new QPushButton("Salva"); buttonSalva->setEnabled(false);
      layoutInfo->addWidget(buttonSalva, 3, 0, 1, 1);

      buttonCerca= new QPushButton("Cerca / Aggiungi");
      layoutInfo->addWidget(buttonCerca, 4, 0, 1, 1);


      // tDiStudio
      gBoxTDiStudio= new QGroupBox("Titoli di studio", this);
      layoutTDiStudio= new QGridLayout();

      tableTDiStudio= new QTableWidget(0, 2);
      tableTDiStudio->setMinimumWidth(150);
      header= QStringList()<<"Titolo"<< "Specializzazione";
      tableTDiStudio->setHorizontalHeaderLabels(header);
      layoutTDiStudio->addWidget(tableTDiStudio, 0, 0, 1, 3);

      buttonAggiungiTDiStudio= new QPushButton("+");
      layoutTDiStudio->addWidget(buttonAggiungiTDiStudio, 1, 0, 1, 1);
      buttonRimuoviTDiStudio= new QPushButton("-");
      layoutTDiStudio->addWidget(buttonRimuoviTDiStudio, 1, 1, 1, 1);

      gBoxTDiStudio->setLayout(layoutTDiStudio);

      layoutInfo->addWidget(gBoxTDiStudio, 0, 2, 1, 1);


      // lingue
      gBoxLingue= new QGroupBox("Lingue", this);
      layoutLingue= new QGridLayout();

      tableLingue= new QTableWidget(0, 1);
      header= QStringList()<<"Lingua";
      tableLingue->setHorizontalHeaderLabels(header);
      layoutLingue->addWidget(tableLingue, 0, 0, 1, 3);

      buttonAggiungiLingua= new QPushButton("+");
      layoutLingue->addWidget(buttonAggiungiLingua, 1, 0, 1, 1);
      buttonRimuoviLingua= new QPushButton("-");
      layoutLingue->addWidget(buttonRimuoviLingua, 1, 1, 1, 1);

      gBoxLingue->setLayout(layoutLingue);

      layoutInfo->addWidget(gBoxLingue, 1, 2, 1, 1);


      // competenze
      gBoxCompetenze= new QGroupBox("Competenze", this);
      layoutCompetenze= new QGridLayout();

      tableCompetenze= new QTableWidget(0, 1);
      header= QStringList()<<"Competenza";
      tableCompetenze->setHorizontalHeaderLabels(header);
      layoutCompetenze->addWidget(tableCompetenze, 0, 0, 1, 3);

      buttonAggiungiCompetenza= new QPushButton("+");
      layoutCompetenze->addWidget(buttonAggiungiCompetenza, 1, 0, 1, 1);
      buttonRimuoviCompetenza= new QPushButton("-");
      layoutCompetenze->addWidget(buttonRimuoviCompetenza, 1, 1, 1, 1);

      gBoxCompetenze->setLayout(layoutCompetenze);

      layoutInfo->addWidget(gBoxCompetenze, 2, 2, 1, 1);


      // esperienze professionali
      gBoxExpProfessionali= new QGroupBox("Esperienze professionali", this);
      layoutExpProfessionali= new QGridLayout();

      tableExpProfessionali= new QTableWidget(0, 3);
      header= QStringList()<<"Dal"<< "Al"<< "Descrizione";
      tableExpProfessionali->setHorizontalHeaderLabels(header);
      layoutExpProfessionali->addWidget(tableExpProfessionali, 0, 0, 1, 3);

      buttonAggiungiExpProfessionale= new QPushButton("+");
      layoutExpProfessionali->addWidget(buttonAggiungiExpProfessionale, 1, 0, 1, 1);
      buttonRimuoviExpProfessionale= new QPushButton("-");
      layoutExpProfessionali->addWidget(buttonRimuoviExpProfessionale, 1, 1, 1, 1);

      gBoxExpProfessionali->setLayout(layoutExpProfessionali);

      layoutInfo->addWidget(gBoxExpProfessionali, 3, 2, 1, 1);

      layoutInfo->setColumnStretch(2, 1);

   gBoxInfo->setLayout(layoutInfo);


   // groupBox rete di contatti
   gBoxRete= new QGroupBox("Rete di contatti", this);
   layoutRete= new QGridLayout();

      // rete di contatti
      tableRete= new QTableWidget(0, 1);
      tableRete->setMaximumWidth(200);
      tableRete->setColumnWidth(0, 200);
      header= QStringList()<<"IdUtente";
      tableRete->setHorizontalHeaderLabels(header);
      layoutRete->addWidget(tableRete, 0, 0, 1, 2);

      buttonRimuoviRete= new QPushButton("-");
      layoutRete->addWidget(buttonRimuoviRete, 1, 0, 1, 1);

   gBoxRete->setLayout(layoutRete);


   layout->addWidget(gBoxInfo);
   layout->addWidget(gBoxRete);

   layout->setStretch(0, 1);

   this->setLayout(layout);


   riempiTableTDiStudio();
   riempiTableLingue();
   riempiTableCompetenze();
   riempiTableExpProfessionali();

   riempiTableRete();


   connect(lineEditNome, SIGNAL(textChanged(QString)), this, SLOT(attivaSalva(QString)));
   connect(lineEditCognome, SIGNAL(textChanged(QString)), this, SLOT(attivaSalva(QString)));
   connect(dateEditDataDiNascita, SIGNAL(dateChanged(QDate)), this, SLOT(attivaSalva(QDate)));
   connect(lineEditEmailDue, SIGNAL(textChanged(QString)), this, SLOT(attivaSalva(QString)));

   connect(buttonSalva, SIGNAL(clicked()), this, SLOT(salva()));
   connect(buttonCerca, SIGNAL(clicked()), this, SLOT(cerca()));

   connect(buttonAggiungiTDiStudio, SIGNAL(clicked()), this, SLOT(aggiungiTDiStudio()));
   connect(buttonAggiungiLingua, SIGNAL(clicked()), this, SLOT(aggiungiLingua()));
   connect(buttonAggiungiCompetenza, SIGNAL(clicked()), this, SLOT(aggiungiCompetenza()));
   connect(buttonAggiungiExpProfessionale, SIGNAL(clicked()), this, SLOT(aggiungiExpProfessionale()));

   connect(buttonRimuoviTDiStudio, SIGNAL(clicked()), this, SLOT(rimuoviTDiStudio()));
   connect(buttonRimuoviLingua, SIGNAL(clicked()), this, SLOT(rimuoviLingua()));
   connect(buttonRimuoviCompetenza, SIGNAL(clicked()), this, SLOT(rimuoviCompetenza()));
   connect(buttonRimuoviExpProfessionale, SIGNAL(clicked()), this, SLOT(rimuoviExpProfessionale()));

   connect(buttonRimuoviRete, SIGNAL(clicked()), this, SLOT(rimuoviRete()));

}


// metodi privati
// riempi tabella titolo di studio
void QtFinestraUtente::riempiTableTDiStudio() {
   int row= tableTDiStudio->rowCount();
   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getTitoloDiStudio().size(); ++i) {
         tableTDiStudio->setRowCount(tableTDiStudio->rowCount()+1);

         QTableWidgetItem* itemTitolo= new QTableWidgetItem (QString::fromStdString(lUtente.getUtente().getProfilo().getTitoloDiStudio(i).getTitolo()));
         tableTDiStudio->setItem(row, 0, itemTitolo);

         QTableWidgetItem* itemSpecializzazione= new QTableWidgetItem (QString::fromStdString(lUtente.getUtente().getProfilo().getTitoloDiStudio(i).getSpecializzazione()));
         tableTDiStudio->setItem(row, 1, itemSpecializzazione);

         ++row;
   }
}

// riempi tabella lingue
void QtFinestraUtente::riempiTableLingue() {
   int row= tableLingue->rowCount();
   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getLingua().size(); ++i) {
         tableLingue->setRowCount(row+1);

         QTableWidgetItem* itemLingua= new QTableWidgetItem (QString::fromStdString(lUtente.getUtente().getProfilo().getLingua(i).getLingua()));
         tableLingue->setItem(row, 0, itemLingua);

         ++row;
   }
}

// riempi tabella competenze
void QtFinestraUtente::riempiTableCompetenze() {
   int row= tableCompetenze->rowCount();
   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getCompetenza().size(); ++i) {
         tableCompetenze->setRowCount(row+1);

         QTableWidgetItem* itemCompetenza= new QTableWidgetItem (QString::fromStdString(lUtente.getUtente().getProfilo().getCompetenza(i).getCompetenza()));
         tableCompetenze->setItem(row, 0, itemCompetenza);

         ++row;
   }
}

// riempi tabella esperienze professionali
void QtFinestraUtente::riempiTableExpProfessionali() {
   int row= tableExpProfessionali->rowCount();
   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getEsperienzaProfessionale().size(); ++i) {
         tableExpProfessionali->setRowCount(row+1);

         QTableWidgetItem* itemDal= new QTableWidgetItem (lUtente.getUtente().getProfilo().getEsperienzaProfessionale(i).getDal().toString("dd.MM.yyyy"));
         tableExpProfessionali->setItem(row, 0, itemDal);

         QTableWidgetItem* itemAl= new QTableWidgetItem (lUtente.getUtente().getProfilo().getEsperienzaProfessionale(i).getAl().toString("dd.MM.yyyy"));
         tableExpProfessionali->setItem(row, 1, itemAl);

         QTableWidgetItem* itemDesc= new QTableWidgetItem (QString::fromStdString(lUtente.getUtente().getProfilo().getEsperienzaProfessionale(i).getDescrizione()));
         tableExpProfessionali->setItem(row, 2, itemDesc);

         ++row;
   }
}

// riempi tabella rete
void QtFinestraUtente::riempiTableRete() {
   int row= 0;
   vector<Contatto> tmp= lUtente.getUtente().getRete();

   for (unsigned int i= 0; i<tmp.size(); ++i) {
      tableRete->setRowCount(row+1);

      QTableWidgetItem* item= new QTableWidgetItem (QString::fromStdString(tmp[i].getContatto()));
      tableRete->setItem(row, 0, item);
   }
}


// private slots
// attiva salva
void QtFinestraUtente::attivaSalva(QString) {
   if (!buttonSalva->isEnabled())
      buttonSalva->setEnabled(true);
}

void QtFinestraUtente::attivaSalva(QDate) {
   attivaSalva(QString());
}


// public slots
// salva
void QtFinestraUtente::salva() {
   lUtente.modificaNome(lineEditNome->text().toStdString());
   lUtente.modificaCognome(lineEditCognome->text().toStdString());
   lUtente.modificaDataDiNascita(dateEditDataDiNascita->date());
   lUtente.modificaEmailSecondaria(lineEditEmailDue->text().toStdString());

   QMessageBox messageBox(this);
   messageBox.setText("Modifiche salvate con successo");
   messageBox.exec();
}

// cerca
void QtFinestraUtente::cerca() {
   QtFinestraCerca finestraCerca(lUtente, this);
   finestraCerca.exec();
   tableRete->clearContents();
   tableRete->setRowCount(0);
   riempiTableRete();
}

// aggiungi titolo di studio
void QtFinestraUtente::aggiungiTDiStudio() {
   QtFinestraTitoloDiStudio finestraTDiStudio(lUtente, this);
   finestraTDiStudio.exec();
   tableTDiStudio->clearContents();
   tableTDiStudio->setRowCount(0);
   riempiTableTDiStudio();
}

// aggiungi lingua
void QtFinestraUtente::aggiungiLingua() {
   QtFinestraLingua finestraLingua(lUtente, this);
   finestraLingua.exec();
   tableLingue->clearContents();
   tableLingue->setRowCount(0);
   riempiTableLingue();
}

// aggiungi competenza
void QtFinestraUtente::aggiungiCompetenza() {
   QtFinestraCompetenza finestraCompetenza (lUtente, this);
   finestraCompetenza.exec();
   tableCompetenze->clearContents();
   tableCompetenze->setRowCount(0);
   riempiTableCompetenze();
}

// aggiungi esperienza professionale
void QtFinestraUtente::aggiungiExpProfessionale() {
   QtFinestraEsperienzaProfessionale finestraExpProfessionale (lUtente, this);
   finestraExpProfessionale.exec();
   tableExpProfessionali->clearContents();
   tableExpProfessionali->setRowCount(0);
   riempiTableExpProfessionali();
}

// rimuovi titolo di studio
void QtFinestraUtente::rimuoviTDiStudio() {
   if (tableTDiStudio->currentItem()!= 0)
      lUtente.rimuoviTitoloDiStudio(tableTDiStudio->currentRow());
   tableTDiStudio->clearContents();
   tableTDiStudio->setRowCount(0);
   riempiTableTDiStudio();
}

// rimuovi lingua
void QtFinestraUtente::rimuoviLingua() {
   if (tableLingue->currentItem()!= 0)
      lUtente.rimuoviLingua(tableLingue->currentRow());
   tableLingue->clearContents();
   tableLingue->setRowCount(0);
   riempiTableLingue();
}

// rimuovi competenza
void QtFinestraUtente::rimuoviCompetenza() {
   if (tableCompetenze->currentItem()!= 0)
      lUtente.rimuoviCompetenza(tableCompetenze->currentRow());
   tableCompetenze->clearContents();
   tableCompetenze->setRowCount(0);
   riempiTableCompetenze();
}

// rimuovi esperienza professionale
void QtFinestraUtente::rimuoviExpProfessionale() {
   if (tableExpProfessionali->currentItem()!= 0)
      lUtente.rimuoviEsperienzaProfessionale(tableExpProfessionali->currentRow());
   tableExpProfessionali->clearContents();
   tableExpProfessionali->setRowCount(0);
   riempiTableExpProfessionali();
}

// rimuovi rete
void QtFinestraUtente::rimuoviRete() {
   if (tableRete->currentItem()!= 0)
      lUtente.rimuoviContatto(tableRete->currentItem()->text().toStdString());
   tableRete->clearContents();
   tableRete->setRowCount(0);
   riempiTableRete();
}
