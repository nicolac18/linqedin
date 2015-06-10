#include "qtfinestrautentevisualizzazione.h"

QtFinestraUtenteVisualizzazione::QtFinestraUtenteVisualizzazione(LinQedInUtente& u, QWidget *parent): QDialog(parent), lUtente(u) {

   this->setWindowTitle(QString("LinQedIn Utente Visualizza"));

   layout= new QHBoxLayout(this);

   // groupBox info
   gBoxInfo= new QGroupBox(QString("Informazioni"), this);
   layoutInfo= new QGridLayout();

      // idUtente
      gBoxIdUtente= new QGroupBox(QString("Id Utente"), this);
      layoutIdUtente= new QGridLayout();

      labelIdUtente= new QLabel(QString("IdUtente (email):"));
      layoutIdUtente->addWidget(labelIdUtente, 0, 0, 1, 1);
      lineEditIdUtente= new QLineEdit(QString::fromStdString(lUtente.getUtente().getId())); lineEditIdUtente->setReadOnly(true);
      lineEditIdUtente->setMinimumWidth(200);
      layoutIdUtente->addWidget(lineEditIdUtente, 0, 1, 1, 1);

      labelPassword= new QLabel(QString("Password:"));
      layoutIdUtente->addWidget(labelPassword, 1, 0, 1, 1);
      lineEditPassword= new QLineEdit(); lineEditPassword->setDisabled(true);
      layoutIdUtente->addWidget(lineEditPassword, 1, 1, 1, 1);

      gBoxIdUtente->setLayout(layoutIdUtente);

      layoutInfo->addWidget(gBoxIdUtente, 0, 0, 1, 1);


      // profilo
      gBoxProfilo= new QGroupBox(QString("Profilo"), this);
      layoutProfilo= new QGridLayout();

      labelNome= new QLabel(QString("Nome:"));
      layoutProfilo->addWidget(labelNome, 0, 0, 1, 1);
      lineEditNome= new QLineEdit(QString::fromStdString(lUtente.getUtente().getProfilo().getNome())); lineEditNome->setReadOnly(true);
      layoutProfilo->addWidget(lineEditNome, 0, 1, 1, 1);

      labelCognome= new QLabel(QString("Cognome:"));
      layoutProfilo->addWidget(labelCognome, 1, 0, 1, 1);
      lineEditCognome= new QLineEdit(QString::fromStdString(lUtente.getUtente().getProfilo().getCognome())); lineEditCognome->setReadOnly(true);
      layoutProfilo->addWidget(lineEditCognome, 1, 1, 1, 1);

      labelDataDiNascita= new QLabel(QString("Data di nascita:"));
      layoutProfilo->addWidget(labelDataDiNascita, 2, 0, 1, 1);
      lineEditDataDiNascita= new QLineEdit((lUtente.getUtente().getProfilo().getDataDiNascita()).toString("dd.MM.yyyy")); lineEditDataDiNascita->setReadOnly(true);
      layoutProfilo->addWidget(lineEditDataDiNascita, 2, 1, 1, 1);

      labelEmailDue= new QLabel(QString("Email secondaria:"));
      layoutProfilo->addWidget(labelEmailDue, 3, 0, 1, 1);
      lineEditEmailDue= new QLineEdit(QString::fromStdString(lUtente.getUtente().getProfilo().getEmailSecondaria())); lineEditEmailDue->setReadOnly(true);
      layoutProfilo->addWidget(lineEditEmailDue, 3, 1, 1, 1);

      gBoxProfilo->setLayout(layoutProfilo);

      layoutInfo->addWidget(gBoxProfilo, 1, 0, 1, 1);


      // tipologia
      gBoxTipologia= new QGroupBox(QString("Tipologia"), this);
      layoutTipologia= new QGridLayout();

      labelTipologia= new QLabel(QString("Tipologia:"));
      layoutTipologia->addWidget(labelTipologia, 0, 0, 1, 1);

      lineEditTipologia= new QLineEdit(QString::fromStdString(lUtente.getUtente().getTipo())); lineEditTipologia->setReadOnly(true);

      layoutTipologia->addWidget(lineEditTipologia, 0, 1, 1, 1);

      gBoxTipologia->setLayout(layoutTipologia);

      layoutInfo->addWidget(gBoxTipologia, 2, 0, 1, 1);


      // altre info
      treeInfo= new QTreeWidget();
      treeInfo->setHeaderHidden(true);
      treeInfo->setColumnCount(1);
      layoutInfo->addWidget(treeInfo, 0, 1, 4, 1);

   gBoxInfo->setLayout(layoutInfo);



   // groupBox rete di contatti
   gBoxRete= new QGroupBox(QString("Rete di contatti"), this);
   layoutRete= new QVBoxLayout();

      // rete di contatti
      textRete= new QListWidget();
      textRete->setMaximumWidth(180);
      layoutRete->addWidget(textRete);

   gBoxRete->setLayout(layoutRete);


   layout->addWidget(gBoxInfo);
   layout->addWidget(gBoxRete);

   this->setLayout(layout);

   riempiTreeInfo();
   riempiTextRete();

}


// metodi privati
void QtFinestraUtenteVisualizzazione::riempiTreeInfo() {

   // titolo di studio
   QTreeWidgetItem* itemTDiStudio= new QTreeWidgetItem(treeInfo);
   itemTDiStudio->setText(0, "Titoli di studio");

   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getTitoloDiStudio().size(); ++i) {
      QTreeWidgetItem* child= new QTreeWidgetItem(itemTDiStudio);
         QString tmp= QString::fromStdString(lUtente.getUtente().getProfilo().getTitoloDiStudio(i).getTitolo());
         tmp.append(", ");
         tmp.append(QString::fromStdString(lUtente.getUtente().getProfilo().getTitoloDiStudio(i).getSpecializzazione()));
      child->setText(0, tmp);
   }

   // lingue
   QTreeWidgetItem* itemLingua= new QTreeWidgetItem(treeInfo);
   itemLingua->setText(0, "Lingua");

   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getLingua().size(); ++i) {
      QTreeWidgetItem* child= new QTreeWidgetItem(itemLingua);
      child->setText(0, QString::fromStdString(lUtente.getUtente().getProfilo().getLingua(i).getLingua()));
   }

   // competenze
   QTreeWidgetItem* itemCompetenza= new QTreeWidgetItem(treeInfo);
   itemCompetenza->setText(0, "Competenze");

   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getCompetenza().size(); ++i) {
      QTreeWidgetItem* child= new QTreeWidgetItem(itemCompetenza);
      child->setText(0,QString::fromStdString(lUtente.getUtente().getProfilo().getCompetenza(i).getCompetenza()));
   }

   // esperienze
   QTreeWidgetItem* itemEsperienza= new QTreeWidgetItem(treeInfo);
   itemEsperienza->setText(0, "Esperienze");

   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getEsperienzaProfessionale().size(); ++i) {

      QTreeWidgetItem* child= new QTreeWidgetItem(itemEsperienza);
         QString tmp ("dal: "); tmp.append(lUtente.getUtente().getProfilo().getEsperienzaProfessionale(i).getDal().toString("dd.MM.yyyy"));
         tmp.append(", al: "); tmp.append(lUtente.getUtente().getProfilo().getEsperienzaProfessionale(i).getAl().toString("dd.MM.yyyy"));
         tmp.append(QString::fromStdString(lUtente.getUtente().getProfilo().getEsperienzaProfessionale(i).getDescrizione()));
      child->setText(0, tmp);
   }
}


void QtFinestraUtenteVisualizzazione::riempiTextRete() {
   QStringList lTmp;
   vector<Contatto>::const_iterator it;
   for (it= lUtente.getUtente().getRete().begin(); it!= lUtente.getUtente().getRete().end(); ++it)
      lTmp<< QString::fromStdString(it->getContatto());
   textRete->addItems(lTmp);
}
