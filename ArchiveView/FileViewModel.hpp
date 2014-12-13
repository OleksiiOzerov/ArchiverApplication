#ifndef FILEVIEWMODEL_HPP
#define FILEVIEWMODEL_HPP

class QAbstractItemModel;
class QObject;

class FileViewModel
{
public:
    FileViewModel(QObject *parent = nullptr);

    QAbstractItemModel * GetItemModel()const;

private:
    QAbstractItemModel * m_ItemModel;
};


#endif // FILEVIEWMODEL_HPP
