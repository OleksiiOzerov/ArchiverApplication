#include "FileViewModel.hpp"
#include "../ArchiverModel/TarArchiver.hpp"

#include <QtWidgets>
#include <ctime>

namespace Archiver
{

void addItem(QAbstractItemModel *model, const QString &name,
             const QString &size, const QString &type, const QString &date)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), name);
    model->setData(model->index(0, 1), size);
    model->setData(model->index(0, 2), type);
    model->setData(model->index(0, 3), date);
}

FileViewModel::FileViewModel(QObject *parent) :
    m_ItemModel(new QStandardItemModel(0, 4, parent)),
    m_Archiver(new TarArchiver())
{
    m_ItemModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    m_ItemModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Size"));
    m_ItemModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    m_ItemModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Modified"));

//    addItem(m_ItemModel, "Happy New Year!", "303.1kB",
//            "GIF image", QDateTime(QDate(2006, 12, 31), QTime(17, 03)));
//    addItem(m_ItemModel, "Radically new concept", "Grace K. <grace@software-inc.com>",
//            QDateTime(QDate(2006, 12, 22), QTime(9, 44)));
}

QAbstractItemModel * FileViewModel::GetItemModel() const
{
    return m_ItemModel;
}

void FileViewModel::OpenArchive(const QString& archiveName)
{
    m_Archiver->OpenArchive(archiveName.toStdString());
    std::vector<Header>& fileCollection = m_Archiver->GetFileCollection();

    for (auto file : fileCollection)
    {
        time_t modificationTime = file.GetFileModificationTime();

        addItem(m_ItemModel, QString::fromStdString(file.GetFileName()),
                QString::number(file.GetFileSize()),
                "GIF image",
                ctime(&modificationTime));

    }


}


}
