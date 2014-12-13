#include "FileViewModel.hpp"

#include <QtWidgets>


void addItem(QAbstractItemModel *model, const QString &subject,
             const QString &sender, const QDateTime &date)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), subject);
    model->setData(model->index(0, 1), sender);
    model->setData(model->index(0, 2), date);
}

FileViewModel::FileViewModel(QObject *parent) :
    m_ItemModel(new QStandardItemModel(0, 3, parent))
{
    m_ItemModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Subject"));
    m_ItemModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Sender"));
    m_ItemModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));

    addItem(m_ItemModel, "Happy New Year!", "Grace K. <grace@software-inc.com>",
            QDateTime(QDate(2006, 12, 31), QTime(17, 03)));
    addItem(m_ItemModel, "Radically new concept", "Grace K. <grace@software-inc.com>",
            QDateTime(QDate(2006, 12, 22), QTime(9, 44)));
    addItem(m_ItemModel, "Accounts", "pascale@nospam.com",
            QDateTime(QDate(2006, 12, 31), QTime(12, 50)));
    addItem(m_ItemModel, "Expenses", "Joe Bloggs <joe@bloggs.com>",
            QDateTime(QDate(2006, 12, 25), QTime(11, 39)));
    addItem(m_ItemModel, "Re: Expenses", "Andy <andy@nospam.com>",
            QDateTime(QDate(2007, 01, 02), QTime(16, 05)));
    addItem(m_ItemModel, "Re: Accounts", "Joe Bloggs <joe@bloggs.com>",
            QDateTime(QDate(2007, 01, 03), QTime(14, 18)));
    addItem(m_ItemModel, "Re: Accounts", "Andy <andy@nospam.com>",
            QDateTime(QDate(2007, 01, 03), QTime(14, 26)));
    addItem(m_ItemModel, "Sports", "Linda Smith <linda.smith@nospam.com>",
            QDateTime(QDate(2007, 01, 05), QTime(11, 33)));
    addItem(m_ItemModel, "AW: Sports", "Rolf Newschweinstein <rolfn@nospam.com>",
            QDateTime(QDate(2007, 01, 05), QTime(12, 00)));
    addItem(m_ItemModel, "RE: Sports", "Petra Schmidt <petras@nospam.com>",
            QDateTime(QDate(2007, 01, 05), QTime(12, 01)));
}

QAbstractItemModel * FileViewModel::GetItemModel() const
{
    return m_ItemModel;
}


