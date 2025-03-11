//
// Created by anton on 3/10/25.
//

#include "WeightMatrix.hpp"
WeightMatrix::WeightMatrix(const int& cnt_rows, const int& cnt_cols,
                           QObject* parent)
    : cnt_rows(cnt_rows), cnt_cols(cnt_cols) {
    for (int i = 0; i < cnt_rows; i++) {
        table.push_back(QVector<int>(cnt_cols));
        for (int j = 0; j < cnt_cols; j++) {
            table.back()[j] = 0;
        }
    }
}
int WeightMatrix::rowCount(const QModelIndex& parent) const {
    return cnt_rows;
}
int WeightMatrix::columnCount(const QModelIndex& parent) const {
    return cnt_cols;
}
int WeightMatrix::getRowCount() const {
    return cnt_rows;
}
int WeightMatrix::getColumnCount() const {
    return cnt_cols;
}
void WeightMatrix::setRowCount(int newValue) {
    beginResetModel();
    table.clear();
    cnt_rows = newValue;
    for (int i = 0; i < cnt_rows; i++) {
        table.push_back(QVector<int>(cnt_cols));
        for (int j = 0; j < cnt_cols; j++) {
            table.back()[j] = 0;
        }
    }
    endResetModel();
    emit sizeChanged();
}
void WeightMatrix::setColumnCount(int newValue) {
    beginResetModel();
    table.clear();
    cnt_cols = newValue;
    for (int i = 0; i < cnt_rows; i++) {
        table.push_back(QVector<int>(cnt_cols));
        for (int j = 0; j < cnt_cols; j++) {
            table.back()[j] = 0;
        }
    }
    endResetModel();
    emit sizeChanged();
}

QVariant WeightMatrix::data(const QModelIndex& index, int role) const {
    switch (role) {
        case kTableDataRole: {
            int val = table.at(index.row()).at(index.column());
            return QString(std::to_string(val).c_str());
        }
        default:
            break;
    }
    return QVariant();
}
QVariant WeightMatrix::headerData(int section, Qt::Orientation orientation,
                                  int role) const {
    return QVariant(section);
}

QHash<int, QByteArray> WeightMatrix::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[kTableDataRole] = "weight";
    return roles;
}
bool WeightMatrix::setData(const QModelIndex& index, const QVariant& value,
                           int role) {
    switch (role) {
        case kTableDataRole: {
            table[index.row()][index.column()] = value.toString().toInt();
            return true;
        }
        default:
            return false;
    }
}
void WeightMatrix::setData(const QVariant& index, const QVariant& value) {
    int r = index.toInt() % cnt_rows;
    int c = index.toInt() / cnt_rows;
    table[r][c] = value.toString().toInt();
    emit dataChanged(this->index(r, c), this->index(r, c));
    emit updated(cnt_rows, index, value);
}
QVariant WeightMatrix::get_display_data(const QModelIndex& index) {
    return data(index, kTableDataRole);
}


