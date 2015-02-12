#include "FileNameDelegate.hpp"

#include <QIcon>
#include <QPainter>

FileNameDelegate::FileNameDelegate(QObject *parent):
    QAbstractItemDelegate(parent)
{
}

QSize FileNameDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(45, 15);
}

void FileNameDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (option.state & QStyle::State_Selected)
        painter->fillRect(option.rect, option.palette.highlight());

    QString fileName = index.model()->data(index, Qt::DisplayRole).toString();

    painter->save();

//    if (factor > 1)
//    {
//        painter->setBrush(Qt::red);
//        factor = 1;
//    }
//    else
//        painter->setBrush(QColor(0, int(factor * 255), 255 - int(factor * 255)));
    QString iconName = m_MimeDataBase.mimeTypeForFile(fileName).iconName();
    QIcon icon = QIcon::fromTheme(iconName);

    icon.paint(painter,
                option.rect.x() + 2, option.rect.y() + 2,
                option.rect.width() / 4, option.rect.height() - 5);

    //painter->setPen(Qt::black);
   // painter->drawRect(option.rect.x() + 2, option.rect.y() + 2,
    //                  int(factor * (option.rect.width() - 5)), option.rect.height() - 5);



    painter->setPen(QPen(Qt::SolidLine));
    painter->drawText(option.rect.x() + option.rect.width() / 4 + 5,
                      option.rect.y() + option.rect.height() - 10, fileName);

    painter->restore();
}

//QWidget *BarDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    QSlider *slider= new QSlider(parent);

//    slider->setAutoFillBackground(true);
//    slider->setOrientation(Qt::Horizontal);
//    slider->setRange(0, 100);
//    slider->installEventFilter(const_cast<BarDelegate*>(this));

//    return slider;
//}

//void BarDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    editor->setGeometry(option.rect);
//}

//void BarDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
//{
//    int value = index.model()->data(index, Qt::DisplayRole).toInt();
//    static_cast<QSlider*>(editor)->setValue(value);
//}

//void BarDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
//{
//    model->setData(index, static_cast<QSlider*>(editor)->value());
//}
