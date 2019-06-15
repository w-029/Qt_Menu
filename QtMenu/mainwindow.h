#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    void initConnect();
    void initCurActions();

private slots:
    void onCheckMenuAction(bool checked);
    void onCheckAction(QAction *checkedAction);

private:
    QAction *curAction;
    QActionGroup *actionGroup;
};

#endif // MAINWINDOW_H
