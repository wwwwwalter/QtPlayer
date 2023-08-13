#include "spacefile.h"

SpaceFile::SpaceFile(QObject *parent)
    : QObject{parent}
{

}

SpaceFile::SpaceFile(const CommomEnum::FileType &type, const QString &name, const QString &path, QObject *parent) : QObject(parent),
    type(type),
    name(name),
    path(path)
{}

SpaceFile::SpaceFile(const SpaceFile &file, QObject *parent):QObject(parent),
    type(file.getType()),
    name(file.getName()),
    path(file.getPath())
{}

CommomEnum::FileType SpaceFile::getType() const
{
    return type;
}

void SpaceFile::setType(const CommomEnum::FileType &newType)
{
    type = newType;
}

QString SpaceFile::getName() const
{
    return name;
}

void SpaceFile::setName(const QString &newName)
{
    name = newName;
}

QString SpaceFile::getPath() const
{
    return path;
}

void SpaceFile::setPath(const QString &newPath)
{
    path = newPath;
}
