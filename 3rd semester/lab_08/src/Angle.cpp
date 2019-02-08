#include <cmath>
#include "Angle.h"

/**
 * @fn correctInRad
 * @brief funkcja zmieniajaca kat na jego odpowiednik w zakresie  [0, 2 * PI]
 */
double correctInRad(double inRad) {
    while(inRad < 0.0 || inRad > M_PI * 2) {
        inRad += inRad > 0.0 ? -2 * M_PI : 2 * M_PI;
    }
    return inRad;
}

Angle::Angle(double inRad) {
    _inRad = inRad;
}

Angle Angle::fromRadians(const double value) {
    return Angle(correctInRad(value));
}

Angle Angle::fromDegrees(const double value) {
    double inRad = correctInRad(value * M_PI / 180);
    return Angle(inRad);
}

Angle Angle::distance(const Angle & angle1, const Angle & angle2) {
    double value = correctInRad(fabs(angle1.toRad() - angle2.toRad()));
    if (value > M_PI) {
        return Angle(2 * M_PI - value);
    }
    return Angle(value);
}

double Angle::toRad() const {
    return _inRad;
}

double Angle::toDeg() const {
    return _inRad * 180 / M_PI;
}

void Angle::add(const Angle & angle) {
    _inRad = correctInRad(_inRad + angle.toRad());
}
