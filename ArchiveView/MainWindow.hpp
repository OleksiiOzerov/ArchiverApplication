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
    void CreateAcitions();
    void CreateMenus();

private slots:
    void NewArchive();
    void OpenArchive();
    void SaveAsArchive();
    void ExtractArchive();

private:
    std::shared_ptr<FileViewModel> m_FileViewModel;

    QSortFilterProxyModel * m_FileListModel;

    QMenu * m_FileMenu;
    QMenu * m_OpenRecentSubMenu;

    QAction * m_NewAction;
    QAction * m_OpenAction;
    QAction * m_OpenRecetnAction;
    QAction * m_SaveAsAction;
    QAction * m_ExtractAction;
    QAction * m_PropertiesAction;
    QAction * m_CloseAction;

};


#endif // MAINWINDOW_HPP
