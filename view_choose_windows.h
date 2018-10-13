#ifndef VIEW_CHOOSE_WINDOWS_H
#define VIEW_CHOOSE_WINDOWS_H

#include <QDialog>

namespace Ui {
class CViewChooseWindows;
}

class CViewChooseWindows : public QDialog
{
    Q_OBJECT

public:
    explicit CViewChooseWindows(QWidget *parent = 0);
    ~CViewChooseWindows();

    void getChooseData(int &nChoose);
    void initStyle();

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CViewChooseWindows *ui;
    int m_nChoose;
};

#endif // VIEW_CHOOSE_WINDOWS_H
