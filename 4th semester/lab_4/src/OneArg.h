#pragma once

/**
 * @class OneArg
 * @brief klasa bazowa dla klas reprezentujacych jednoargumentowe operacje logiczne
 */
class OneArg {
public:
    virtual bool result(const bool cond1) const = 0;
    virtual ~OneArg() = default;
};

/**
 * @class NOT
 * @brief klasa pochodna reprezentujaca operacje logiczna not, dziedziczy po klasie OneArg, poniewaz not jest operacja jednoargumentowa
 */
class NOT : public OneArg {
public:
    bool result(const bool cond1) const override;
};