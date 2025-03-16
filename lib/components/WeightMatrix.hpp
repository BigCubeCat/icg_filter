#pragma once

#include <QtQmlIntegration/qqmlintegration.h>

#include <QAbstractItemModel>
#include <QObject>

class WeightMatrix : public QAbstractListModel {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int rows READ getRowCount WRITE setRowCount NOTIFY sizeChanged)
    Q_PROPERTY(int columns READ getColumnCount WRITE setColumnCount NOTIFY sizeChanged)
    enum TableRoles {
        kTableDataRole = Qt::UserRole + 1,
    };

   public:
    explicit WeightMatrix(const int& cnt_rows = 1, const int& cnt_cols = 1,
                          QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent) const override;
    int columnCount(const QModelIndex& parent) const override;
    int getRowCount() const;
    int getColumnCount() const;
    void setRowCount(int newValue);
    void setColumnCount(int newValue);
    QVariant data(const QModelIndex& index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    bool setData(const QModelIndex& index, const QVariant& value,
                 int role) override;
    Q_INVOKABLE void setData(const QVariant& index, const QVariant& value);
    Q_INVOKABLE QVariant get_display_data(const QModelIndex& index);

    signals:
    void sizeChanged();
    void updated(const QVariant& rows, const QVariant& index,const QVariant &value);

   private:
    QVector<QVector<int>> table;
    int cnt_rows = 1;
    int cnt_cols = 1;
};
