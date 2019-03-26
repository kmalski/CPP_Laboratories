#pragma once

/**
 * @class TwoArg
 * @brief klasa bazowa dla klas reprezentujacych dwuargumentowe operacje logiczne
 */
class TwoArg {
public:
    virtual bool result(const bool cond1, const bool cond2) const = 0;
    virtual ~TwoArg() = default;
};

/**
 * @class OR
 * @brief klasa pochodna reprezentujaca operacje logiczna or, dziedziczy po klasie TwoArg, poniewaz or to operacja dwuargumentowa
 */
class OR : public TwoArg {
public:
    bool result(const bool cond1, const bool cond2) const override;
};

/**
 * @class AND
 * @brief klasa pochodna reprezentujaca operacje logiczna and, dziedziczy po klasie OneArg, poniewaz and jest operacja dwuargumentowa
 */
class AND : public TwoArg {
public:
    bool result(const bool cond1, const bool cond2) const override;
};