#include <qtmetamacros.h>
#include <QObject>

/*!
 * \brief перенаправляет сигналы на нужные слоты. позволяет соеденить model и view
  */
class SignalController : public QObject {
    Q_OBJECT
   public:
    explicit SignalController() = default;

   signals:
    void applyFilterSignal();

   public slots:
    void applyFilterSlot();
};
