#ifndef FILEVIEWMODEL_HPP
#define FILEVIEWMODEL_HPP

#include <memory>

class QAbstractItemModel;
class QObject;
class QString;


namespace Archiver
{

class TarArchiver;

class FileViewModel
{
public:
    FileViewModel(QObject *parent = nullptr);

    void OpenArchive(const QString& archiveName);

    QAbstractItemModel * GetItemModel()const;

private:
    QAbstractItemModel * m_ItemModel;

    std::shared_ptr<TarArchiver> m_Archiver;
};
}

#endif // FILEVIEWMODEL_HPP
