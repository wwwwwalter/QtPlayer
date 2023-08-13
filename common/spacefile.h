#ifndef SPACEFILE_H
#define SPACEFILE_H

#include <QObject>
#include "commomenum.h"

class SpaceFile : public QObject
{
    Q_OBJECT
public:
    explicit SpaceFile(QObject *parent = nullptr);
    SpaceFile(const CommomEnum::FileType &type, const QString &name, const QString &path, QObject *parent = nullptr);
    SpaceFile(const SpaceFile &file, QObject *parent = nullptr);


    CommomEnum::FileType getType() const;
    void setType(const CommomEnum::FileType &newType);
    QString getName() const;
    void setName(const QString &newName);
    QString getPath() const;
    void setPath(const QString &newPath);

private:
    CommomEnum::FileType type;
    QString name;
    QString path;

signals:

};

#endif // SPACEFILE_H
