#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initCurActions();
    initConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initCurActions() {
    curAction = ui->action_radio_1;

    actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->action_new);
    actionGroup->addAction(ui->action_save);
}

void MainWindow::initConnect() {
    connect(ui->action_radio_1, SIGNAL(triggered(bool)), this, SLOT(onCheckMenuAction(bool)));
    connect(ui->action_radio_2, SIGNAL(triggered(bool)), this, SLOT(onCheckMenuAction(bool)));

    connect(actionGroup, SIGNAL(triggered(QAction*)), this, SLOT(onCheckAction(QAction*)));
}

void MainWindow::onCheckMenuAction(bool checked) {
    curAction->setChecked(false);
    curAction = qobject_cast<QAction *>(sender());
    curAction->setChecked(true);

    QMessageBox::warning(this, "菜单响应", tr("我是").append(curAction->objectName()).append(tr(",我通过监听单个菜单项来响应")));
}

void MainWindow::onCheckAction(QAction *checkedAction) {

    if (checkedAction->objectName() == "action_new") {
        QMessageBox::warning(this, "菜单响应", tr("我是action_new我通过监听菜单组来响应"));
    } else if (checkedAction->objectName() == "action_save") {
        QMessageBox::warning(this, "菜单响应", tr("我是action_save我通过监听菜单组来响应"));
    }
}
