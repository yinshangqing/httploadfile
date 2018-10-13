#include "view_choose_windows.h"
#include "ui_view_choose_windows.h"
#include <QFile>

CViewChooseWindows::CViewChooseWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CViewChooseWindows),
    m_nChoose(0)
{
    ui->setupUi(this);
    initStyle();
    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    ui->radBtn1920->setChecked(true);
//    connect(ui->frmTitle, SIGNAL(SIGNAL_close()), this, SLOT(close()));
}

CViewChooseWindows::~CViewChooseWindows()
{
    delete ui;
}

void CViewChooseWindows::getChooseData(int &nChoose)
{
    nChoose = m_nChoose;
}

void CViewChooseWindows::initStyle()
{
    QFile file(":/main/resource/qss/choose.qss");
    if(file.open(QFile::ReadOnly))
    {
        this->setStyleSheet(file.readAll());
        file.close();
    }
}

void CViewChooseWindows::closeEvent(QCloseEvent *)
{

}

void CViewChooseWindows::on_pushButton_clicked()
{
//    m_nChoose = ui->comboBox->currentIndex();
    this->accept();
}
