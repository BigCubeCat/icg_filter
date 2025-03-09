#pragma once

#include <QImage>
#include <QJsonObject>

#include "i_filter.hpp"

class SepiaFilter : public IFilter {
   public:
    ~SepiaFilter() = default;

    QJsonObject json() const override {
        QJsonObject object{};
        QJsonObject coef{};
        coef["name"] = "коэффицент";
        coef["type"] = "int";
        coef["min"] = 3;
        coef["max"] = 255;
        coef["step"] = 1;
        coef["default"] = 10;
        object["sepia"] = coef;
        return object;
    }

    std::string name() const override { return "sepia"; }

    void apply([[maybe_unused]] QImage& image) override {
        const int width = image.width();
        const int height = image.height();

        for (int y = 0; y < height; ++y) {
            QRgb* scan_line = reinterpret_cast<QRgb*>(image.scanLine(y));

            for (int x = 0; x < width; ++x) {
                QRgb pixel = scan_line[x];

                // Извлекаем цветовые компоненты
                int r = qRed(pixel);
                int g = qGreen(pixel);
                int b = qBlue(pixel);
                // Применяем преобразование сепии
                int new_red = qMin(
                    static_cast<int>((r * 0.393) + (g * 0.769) + (b * 0.189)),
                    255);
                int new_green = qMin(
                    static_cast<int>((r * 0.349) + (g * 0.686) + (b * 0.168)),
                    255);
                int new_blue = qMin(
                    static_cast<int>((r * 0.272) + (g * 0.534) + (b * 0.131)),
                    255);

                // Сохраняем альфа-канал без изменений
                scan_line[x] =
                    qRgba(new_red, new_green, new_blue, qAlpha(pixel));
            }
        }
    }
};
