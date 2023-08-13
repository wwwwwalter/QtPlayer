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



    enum FileType{
        Video,
        Audio,
        Picture,
        Stream,
        Model,
    };
    Q_ENUM(FileType)


signals:

};

#endif // COMMOMENUM_H
