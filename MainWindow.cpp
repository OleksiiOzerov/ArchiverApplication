#include "MainWindow.hpp"

#include <QtWidgets>

MainWindow::MainWindow()
{
    QTableWidget * tableWidget = new QTableWidget(this);

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(0);
    tableWidget->setRowCount(5);
    tableWidget->setColumnCount(5);

    tableWidget->setShowGrid(false);
    tableWidget->verticalHeader()->setVisible(false);

    setCentralWidget(tableWidget);

    CreateAcitions();
    CreateMenus();


//    setObjectName(QStringLiteral("MainWindow"));
//    resize(400, 300);

//    QWidget * centralWidget = new QWidget(this);
//    centralWidget->setObjectName(QStringLiteral("centralWidget"));
//    setCentralWidget(centralWidget);

//    setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
}


void MainWindow::NewArchive()
{

}

void MainWindow::OpenArchive()
{

}

void MainWindow::SaveAsArchive()
{

}

void MainWindow::ExtractArchive()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}


void MainWindow::CreateAcitions()
{
    //New
    m_NewAction = new QAction(tr("&New"), this);
    m_NewAction->setShortcut(QKeySequence::New);
    m_NewAction->setStatusTip(tr("Create a new archive"));
    connect(m_NewAction, SIGNAL(triggered()), this, SLOT(NewArchive()));

    //Open
    m_OpenAction = new QAction(tr("&Open"), this);
    m_OpenAction->setShortcut(QKeySequence::Open);
    m_OpenAction->setStatusTip(tr("Create a new archive"));
    connect(m_OpenAction, SIGNAL(triggered()), this, SLOT(OpenArchive()));

    //SaveAs
    m_SaveAsAction = new QAction(tr("&Save As"), this);
    m_SaveAsAction->setShortcut(QKeySequence::SaveAs);
    m_SaveAsAction->setStatusTip(tr("Save archive as"));
    connect(m_SaveAsAction, SIGNAL(triggered()), this, SLOT(SaveAsArchive()));

    //Extract
    m_ExtractAction = new QAction(tr("&Extract"), this);
    m_ExtractAction->setStatusTip(tr("Extract archive"));
    connect(m_ExtractAction, SIGNAL(triggered()), this, SLOT(ExtractArchive()));

    //Close
    m_CloseAction = new QAction(tr("&Close"), this);
    m_CloseAction->setShortcut(QKeySequence::Close);
    m_CloseAction->setStatusTip(tr("Close archive"));
    connect(m_CloseAction, SIGNAL(triggered()), this, SLOT(close()));

}

void MainWindow::CreateMenus()
{
    m_FileMenu = menuBar()->addMenu(tr("&Archive"));
    m_FileMenu->addAction(m_NewAction);
    m_FileMenu->addAction(m_OpenAction);

    m_OpenRecentSubMenu = m_FileMenu->addMenu(tr("Open Recent"));

    m_FileMenu->addSeparator();
    m_FileMenu->addAction(m_ExtractAction);
    m_FileMenu->addSeparator();
    m_FileMenu->addAction(m_CloseAction);

}
