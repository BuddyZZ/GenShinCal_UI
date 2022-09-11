#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include "Calculate/calculate.h"

using namespace genShinImpact;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("GenShinCal 1.0,0");

    QDoubleValidator* temp=new QDoubleValidator;
    ui->lineEdit_10->setValidator(temp) ;
    ui->lineEdit_11->setValidator(temp) ;
    ui->lineEdit_12->setValidator(temp ) ;
    ui->lineEdit_13->setValidator(temp ) ;
    ui->lineEdit_14->setValidator(temp ) ;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    calculate* cal= new calculate();
    cal->resetAll();

    cal->mSuffer.info.level=ui->lineEdit_18->text().toUInt();
    cal->mSuffer.res.anemo=ui->lineEdit_38->text().toFloat();

    cal->mAttacker.info.level = ui->lineEdit_17->text().toUInt();
    cal->mAttacker.attrB.atkFix = ui->lineEdit_10->text().toFloat();
    cal->mAttacker.attrB.defFix = ui->lineEdit_12->text().toFloat();
    cal->mAttacker.attrB.hpFix = ui->lineEdit_11->text().toFloat();
    cal->mAttacker.attr.critDmg = ui->lineEdit_14->text().toFloat()/100;
    cal->mAttacker.attr.critRate = ui->lineEdit_13->text().toFloat()/100;
    cal->mAttacker.attr.elementalMastery =ui->lineEdit_16->text().toFloat();
    cal->mAttacker.bonus.anemo = ui->lineEdit_15->text().toFloat()/100;


    ui->comboBox->count();
    float rate=ui->lineEdit_45->text().toFloat()/100;
    eReactType reactType=static_cast<eReactType> (ui->comboBox->currentIndex());
    eTextType basicVal=static_cast<eTextType> (ui->comboBox_2->currentIndex());

    float damageMax = cal->calDamage(rate, reactType, basicVal, CAL_MAX, DAMAGE_UNSURE, ELEMENT_ANEMO);
    float damageExp = cal->calDamage(rate, reactType, basicVal, CAL_EXPECTANCE, DAMAGE_UNSURE, ELEMENT_ANEMO);
    float damageMin = cal->calDamage(rate, reactType, basicVal, CAL_MIN, DAMAGE_UNSURE, ELEMENT_ANEMO);


    QString temp;
//    temp.asprintf("Max DMG==%.2f\n Expect DMG==%.2f\n Min DMG==%.2f\n",damageMax,damageExp,damageMin);
    temp=QString::asprintf("Max DMG==%.2f;\nExpect DMG==%.2f;\nMin DMG==%.2f;\n",damageMax,damageExp,damageMin);

    ui->plainTextEdit->setPlainText(temp);
//    delete cal;
}


void MainWindow::on_plainTextEdit_textChanged()
{

}


void MainWindow::on_lineEdit_10_editingFinished()
{

}

