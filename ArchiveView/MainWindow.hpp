#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

//#include "FileViewModel.hpp"

class FileViewModel;

#include <QMainWindow>

#include <memory>

class QAction;
class QSortFilterProxyModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private:
    QWidget * GetCentralWidget();

    void CreateAcitions();
    void CreateMenus();
    void CreateToolBar();
    void CreateStatusBar();


    void ReadSettings();
    void WriteSettings();

private slots:
    void NewArchive();
    void OpenArchive();
    void SaveAsArchive();
    void ExtractArchive();

private:
    std::shared_ptr<FileViewModel> m_FileViewModel;

    QSortFilterProxyModel * m_FileListModel;

    //All Menus
    QMenu * m_FileMenu;
    QMenu * m_OpenRecentSubMenu;
    QMenu * m_EditMenu;
    QMenu * m_ViewMenu;
    QMenu * m_HelpMenu;

    //ToolBars
    QToolBar *m_ArchiveToolBar;
    QToolBar *m_EditToolBar;
    QToolBar *m_ViewToolBar;

    //Archive menu Actions
    QAction * m_NewAction;
    QAction * m_OpenAction;
    QAction * m_OpenRecetnAction;
    QAction * m_SaveAsAction;
    QAction * m_ExtractAction;
    QAction * m_PropertiesAction;
    QAction * m_CloseAction;

    //Edit menu Actions
    QAction * m_CutAction;
    QAction * m_CopyAction;
    QAction * m_PasteAction;
    QAction * m_RenameAction;
    QAction * m_DeleteAction;
    QAction * m_SelectAllAction;
    QAction * m_DeselectAllAction;
    QAction * m_FindAction;
    QAction * m_AddFilesAction;
    QAction * m_AddAFolderAction;
    QAction * m_PasswordAction;

    //View menu Actions
    QAction * m_ToolbarAction;
    QAction * m_StatusbarAction;
    QAction * m_FoldersAction;
    QAction * m_ViewAllFilesAction;
    QAction * m_ViewAsAFolderAction;
    QAction * m_StopAction;
    QAction * m_RefreshAction;

    //Help menu Actions
    QAction * m_AboutAction;
};


#endif // MAINWINDOW_HPP
