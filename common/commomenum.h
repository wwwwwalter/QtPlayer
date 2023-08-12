#ifndef COMMOMENUM_H
#define COMMOMENUM_H

#include <QObject>

class CommomEnum : public QObject
{
    Q_OBJECT
public:
    explicit CommomEnum(QObject *parent = nullptr);


    enum SpaceType{
        Grid,
        Splitter,
    };
    Q_ENUM(SpaceType)


signals:

};

#endif // COMMOMENUM_H
