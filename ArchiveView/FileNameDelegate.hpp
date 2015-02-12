#ifndef FILENAMEDELEGATE_HPP
#define FILENAMEDELEGATE_HPP

#include <QAbstractItemDelegate>
#include <QMimeDatabase>

class FileNameDelegate : public QAbstractItemDelegate
{
    Q_OBJECT

public:
    explicit FileNameDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    //QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    //void setEditorData(QWidget *editor, const QModelIndex &index) const;

    //void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    //void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:
    QMimeDatabase m_MimeDataBase;
};

#endif // FILENAMEDELEGATE_HPP
