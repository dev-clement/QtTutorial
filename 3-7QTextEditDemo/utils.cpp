#include "utils.h"

Utils* Utils::_utils = nullptr;

Utils *Utils::instance() {
    if (_utils == nullptr) {
        _utils = new Utils{};
    }
    return _utils;
}

TextHandler Utils::getHandlerByName(const QVector<TextHandler> &pBtnList, const QString &pName) {
    auto it = std::find_if(pBtnList.begin(), pBtnList.end(), [=](const TextHandler lhs){ return lhs.getName() == pName; });
    if (it == pBtnList.end())
        throw std::runtime_error("Button with the specified name isn't found");
    return *it;
}
