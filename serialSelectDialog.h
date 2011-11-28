#ifndef SERIALSELECTDIALOG_H
#define SERIALSELECTDIALOG_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
    class SerialSelectDialog;
}

class SerialSelectDialog : public QDialog
{
    Q_OBJECT
private:
    Ui::SerialSelectDialog *ui;

private slots:
    void doubleClicked(QModelIndex index);

public:
    explicit SerialSelectDialog(QWidget *parent = 0);
    ~SerialSelectDialog();

    QString SelectedPort();
};

#endif // SERIALSELECTDIALOG_H
