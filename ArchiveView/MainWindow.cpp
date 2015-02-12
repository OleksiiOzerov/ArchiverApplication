#include "MainWindow.hpp"
#include "FileViewModel.hpp"
#include "FileNameDelegate.hpp"

#include <QtWidgets>

namespace Archiver
{
QWidget * MainWindow::GetCentralWidget()
{
    //Central Widget
    m_FileListModel = new QSortFilterProxyModel;

    QTreeView * fileListView = new QTreeView;
    fileListView->setRootIsDecorated(false);
    fileListView->setAlternatingRowColors(true);
    fileListView->setModel(m_FileListModel);
    fileListView->setSortingEnabled(true);

    fileListView->sortByColumn(1, Qt::AscendingOrder);

    FileNameDelegate *delegate = new FileNameDelegate;
    fileListView->setItemDelegateForColumn(0, delegate);

    m_FileListModel->setSourceModel(m_FileViewModel->GetItemModel());

    return fileListView;
}

MainWindow::MainWindow() : m_FileViewModel(new FileViewModel(this))
{
    //Central View
    QWidget * centralWidget = GetCentralWidget();
    setCentralWidget(centralWidget);

    //Menu and Toolbars
    CreateAcitions();
    CreateMenus();
    CreateToolBar();
    CreateStatusBar();

    ReadSettings();

    //Main Window setup
    setWindowTitle(tr("Archive"));
//    setObjectName(QStringLiteral("MainWindow"));

//    setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
}


void MainWindow::NewArchive()
{
    QFileDialog dialog(this, tr("New Archive"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setLabelText(QFileDialog::Accept, "New");
    dialog.exec();
    QStringList files = dialog.selectedFiles();
}

void MainWindow::OpenArchive()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                               tr("Open Archive"), ".",
                               tr("Tar archive (*.tar)"));

    m_FileViewModel->OpenArchive(fileName);
    m_FileListModel->setSourceModel(m_FileViewModel->GetItemModel());
}

void MainWindow::SaveAsArchive()
{
    QFileDialog dialog(this, tr("Save As"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.exec();
    QStringList files = dialog.selectedFiles();
}

void MainWindow::ExtractArchive()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    WriteSettings();
    event->accept();
}

void MainWindow::CreateAcitions()
{
    /* ## Archive Menu ## */
    //New
    m_NewAction = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
    m_NewAction->setShortcut(QKeySequence::New);
    m_NewAction->setStatusTip(tr("Create a new archive"));
    connect(m_NewAction, SIGNAL(triggered()), this, SLOT(NewArchive()));

    //Open
    m_OpenAction = new QAction(QIcon(":/images/open.png"), tr("&Open"), this);
    m_OpenAction->setShortcut(QKeySequence::Open);
    m_OpenAction->setStatusTip(tr("Open archive"));
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

    /* ## Edit Menu ## */
    //Cut
    m_CutAction = new QAction(tr("&Cut"), this);
    m_CutAction->setShortcut(QKeySequence::Cut);

    //Copy
    m_CopyAction = new QAction(tr("C&opy"), this);
    m_CopyAction->setShortcut(QKeySequence::Copy);

    //Paste
    m_PasteAction = new QAction(tr("&Paste"), this);
    m_PasteAction->setShortcut(QKeySequence::Paste);

    //Rename
    m_RenameAction = new QAction(tr("&Rename"), this);

    //Delete
    m_DeleteAction = new QAction(tr("&Delete"), this);
    m_DeleteAction->setShortcut(QKeySequence::Delete);

    //Select All
    m_SelectAllAction = new QAction(tr("&Select All"), this);
    m_SelectAllAction->setShortcut(QKeySequence::SelectAll);

    //Deselect All
    m_DeselectAllAction = new QAction(tr("&Deselect All"), this);
    m_DeselectAllAction->setShortcut(QKeySequence::Deselect);

    //Find
    m_FindAction = new QAction(tr("&Find"), this);
    m_FindAction->setShortcut(QKeySequence::Find);

    //Add files
    m_AddFilesAction = new QAction(tr("A&dd Files"), this);

    //Add folder action
    m_AddAFolderAction = new QAction(tr("A&dd Folder"), this);

    //Password
    m_PasswordAction = new QAction(tr("&Password"), this);

    /* ## View Menu ## */
    //Toolbar
    m_ToolbarAction = new QAction(tr("&Toolbar"), this);

    //Statusbar
    m_StatusbarAction = new QAction(tr("&Statusbar"), this);

    //Folder
    m_FoldersAction = new QAction(tr("&Folder"), this);

    //View All Files
    m_ViewAllFilesAction = new QAction(tr("&View all files"), this);

    //View as a Folder
    m_ViewAsAFolderAction = new QAction(tr("View &as a Folder"), this);

    //Stop
    m_StopAction = new QAction(tr("&Stop"), this);

    //Refresh
    m_RefreshAction = new QAction(tr("&Refresh"), this);

    /* ## Help Menu ## */
    //About
    m_AboutAction = new QAction(tr("&About"), this);
}

void MainWindow::CreateMenus()
{
    /* ## Archive Menu ## */
    m_FileMenu = menuBar()->addMenu(tr("&Archive"));
    m_FileMenu->addAction(m_NewAction);
    m_FileMenu->addAction(m_OpenAction);
    m_FileMenu->addAction(m_SaveAsAction);
    m_OpenRecentSubMenu = m_FileMenu->addMenu(tr("Open Recent"));
    m_FileMenu->addSeparator();
    m_FileMenu->addAction(m_ExtractAction);
    m_FileMenu->addSeparator();
    m_FileMenu->addAction(m_CloseAction);

    /* ## Edit Menu ## */
    m_EditMenu = menuBar()->addMenu(tr("&Edit"));
    m_EditMenu->addAction(m_CutAction);
    m_EditMenu->addAction(m_CopyAction);
    m_EditMenu->addAction(m_PasteAction);
    m_EditMenu->addAction(m_RenameAction);
    m_EditMenu->addAction(m_DeleteAction);
    m_EditMenu->addSeparator();
    m_EditMenu->addAction(m_SelectAllAction);
    m_EditMenu->addAction(m_DeselectAllAction);
    m_EditMenu->addSeparator();
    m_EditMenu->addAction(m_FindAction);
    m_EditMenu->addSeparator();
    m_EditMenu->addAction(m_AddFilesAction);
    m_EditMenu->addAction(m_AddAFolderAction);
    m_EditMenu->addSeparator();
    m_EditMenu->addAction(m_PasswordAction);

    /* ## View Menu ## */
    m_ViewMenu = menuBar()->addMenu(tr("&View"));
    m_ViewMenu->addAction(m_ToolbarAction);
    m_ViewMenu->addAction(m_StatusbarAction);
    m_ViewMenu->addAction(m_FoldersAction);
    m_ViewMenu->addAction(m_ViewAllFilesAction);
    m_ViewMenu->addAction(m_ViewAsAFolderAction);
    m_ViewMenu->addAction(m_StopAction);
    m_ViewMenu->addAction(m_RefreshAction);

    /* ## Help Menu ## */
    m_HelpMenu = menuBar()->addMenu(tr("&Help"));
    m_HelpMenu->addAction(m_AboutAction);
}

void MainWindow::CreateToolBar()
{
    m_ArchiveToolBar = addToolBar(tr("Archive"));
    m_ArchiveToolBar->addAction(m_NewAction);
    m_ArchiveToolBar->addAction(m_OpenAction);
//    m_ArchiveToolBar->addAction(m_OpenRecetnAction);
//    m_ArchiveToolBar->addSeparator();
//    m_ArchiveToolBar->addAction(m_ExtractAction);

//    m_EditToolBar = addToolBar(tr("Edit"));
//    m_EditToolBar->addAction(m_AddFilesAction);
//    m_EditToolBar->addAction(m_AddAFolderAction);

//    m_ViewToolBar = addToolBar(tr("View"));
//    m_ViewToolBar->addAction(m_StopAction);
}

void MainWindow::CreateStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::ReadSettings()
{
    QSettings settings("QtProject", "Archiver Application");

    restoreGeometry(settings.value("geometry").toByteArray());
}

void MainWindow::WriteSettings()
{
    QSettings settings("QtProject", "Archiver Application");

    settings.setValue("geometry", saveGeometry());
}
}
