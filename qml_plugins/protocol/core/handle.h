#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_HANDLE_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_HANDLE_H_
#include <QString>
#include <QVariantMap>

typedef int HandleId;

struct Handle
{
    HandleId uid;
    int code;
    QString message;
    explicit Handle(HandleId id) : uid(id), code(0), message() {}
    Handle(const QVariantMap& map) {
        uid = map["uid"].toInt();
        code = map["code"].toInt();
        message = map["message"].toString();
    }
    operator QVariantMap() const {
        QVariantMap map;
        map["uid"] = QVariant::fromValue(uid);
        map["code"] = QVariant::fromValue(code);
        map["message"] = QVariant::fromValue(message);
        return map;
    }
};

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_HANDLE_H_
