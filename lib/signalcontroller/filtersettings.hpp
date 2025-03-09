// filtersettings.h
#include <QObject>

class FilterSettings : public QObject {
    Q_OBJECT
    Q_PROPERTY(double brightness READ brightness WRITE setBrightness NOTIFY
                   brightnessChanged)
    Q_PROPERTY(
        double contrast READ contrast WRITE setContrast NOTIFY contrastChanged)

   public:
    explicit FilterSettings(QObject* parent = nullptr) : QObject(parent) {}

    double brightness() const { return m_brightness; }
    void setBrightness(double value) {
        if (m_brightness != value) {
            m_brightness = value;
            emit brightnessChanged(value);
        }
    }

    double contrast() const { return m_contrast; }
    void setContrast(double value) {
        if (m_contrast != value) {
            m_contrast = value;
            emit contrastChanged(value);
        }
    }

   signals:
    void brightnessChanged(double value);
    void contrastChanged(double value);

   private:
    double m_brightness = 1.0;
    double m_contrast = 1.0;
};
