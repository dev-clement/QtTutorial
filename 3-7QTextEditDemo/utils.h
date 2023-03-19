#ifndef UTILS_H
#define UTILS_H

#include <QVector>
#include "texthandler.h"

/**
 * @brief The Utils class is a class used for some utility situation
 * inside of the code. For instance, if we want to fetch a specific
 * button inside of a vector using the find_if algorithms, we are
 * going to use the method used inside this object.
 * Of course this object is static because only one instance is needed
 */
class Utils
{
public:
    Utils(const Utils& lhs) = delete;
    Utils& operator=(const Utils& lhs) = delete;
    static Utils *instance();
public:
    TextHandler getHandlerByName(const QVector<TextHandler> &pBtnList, const QString &pName);
protected:
    Utils() = default;
private:
    static Utils* _utils;
};

#endif // UTILS_H
