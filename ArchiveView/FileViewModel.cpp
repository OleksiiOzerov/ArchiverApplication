#include "FileViewModel.hpp"
#include "../ArchiverModel/TarArchiver.hpp"


#include <QtWidgets>
#include <QMimeDatabase>
#include <ctime>

namespace Archiver
{

void FileViewModel::addItem(const QString &name,
             const QString &size, const QString &type, const QString &date)
{

    QList<QStandardItem*> rowItems;

    QStandardItem *nameItem = new QStandardItem(name);
    QStandardItem *sizeItem = new QStandardItem(size);
    QStandardItem *typeItem = new QStandardItem(type);
    QStandardItem *dateItem = new QStandardItem(date);

    nameItem->setEditable(false);
    sizeItem->setEditable(false);
    typeItem->setEditable(false);
    dateItem->setEditable(false);

    rowItems.push_back(nameItem);
    rowItems.push_back(sizeItem);
    rowItems.push_back(typeItem);
    rowItems.push_back(dateItem);

    m_ItemModel->insertRow(0, rowItems);


//    m_ItemModel->setData(m_ItemModel->index(0, 0), name, Qt::DisplayRole);
//    m_ItemModel->setData(m_ItemModel->index(0, 1), size, Qt::DisplayRole);
//    m_ItemModel->setData(m_ItemModel->index(0, 2), type, Qt::DisplayRole);
//    m_ItemModel->setData(m_ItemModel->index(0, 3), date, Qt::DisplayRole);
}

FileViewModel::FileViewModel(QObject *parent) :
    m_ItemModel(new QStandardItemModel(0, 4, parent)),
    m_Archiver(new TarArchiver())
{
    m_ItemModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    m_ItemModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Size"));
    m_ItemModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    m_ItemModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Modified"));
}

QAbstractItemModel * FileViewModel::GetItemModel() const
{
    return m_ItemModel;
}

void FileViewModel::OpenArchive(const QString& archiveName)
{
    m_Archiver->OpenArchive(archiveName.toStdString());
    std::vector<Header>& fileCollection = m_Archiver->GetFileCollection();
    QMimeDatabase db;

    for (auto file : fileCollection)
    {
        time_t modificationTime = file.GetFileModificationTime();
        QString fileName = QString::fromStdString(file.GetFileName());

        addItem(fileName,
                QString::number(file.GetFileSize()),
                db.mimeTypeForFile(fileName).name(),
                ctime(&modificationTime));
    }


}


}
