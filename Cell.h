#ifndef CELL_H
#define CELL_H

#include <QObject>

class Cell : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged FINAL)
public:
    explicit Cell(QString s, QObject *parent = nullptr);


    QString value() const;
    void setValue(const QString &newValue);
    void setValueWithoutSignal(const QString& value);

signals:
    void valueChanged();
private:
    QString m_value;
};

#endif // CELL_H
