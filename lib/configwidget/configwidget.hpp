#pragma once

#include <QJsonObject>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ConfigWidget;
}
QT_END_NAMESPACE

class ConfigWidget : public QWidget {
    Q_OBJECT
   public:
    explicit ConfigWidget(QWidget* parent = nullptr);
    ~ConfigWidget() override;

   private slots:
    void updateView();

   public:
   signals:
    void configChanged();

   private:
    Ui::ConfigWidget* m_ui;
    QJsonObject m_current;
};
