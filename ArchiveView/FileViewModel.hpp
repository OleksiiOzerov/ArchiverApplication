#ifndef FILEVIEWMODEL_HPP
#define FILEVIEWMODEL_HPP

#include <memory>

class QStandardItemModel;
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
    void addItem(const QString &name, const QString &size,
                 const QString &type, const QString &date);

    QStandardItemModel * m_ItemModel;

    std::shared_ptr<TarArchiver> m_Archiver;
};
}

#endif // FILEVIEWMODEL_HPP
