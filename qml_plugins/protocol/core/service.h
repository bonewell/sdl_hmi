#ifndef SERVICE_H
#define SERVICE_H

#include <QString>

class Service
{
 public:
  explicit Service(const QString& name);
  void run();

 private:
  QString name_;
};

#endif // SERVICE_H
