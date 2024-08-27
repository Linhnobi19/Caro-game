#include "Cell.h"
#include <QDebug>

Cell::Cell(QString s, QObject *parent)
    : QObject{parent}, m_value(s)
{}

QString Cell::value() const
{
    return m_value;
}

void Cell::setValue(const QString &newValue)
{
    if (m_value == newValue)
        return;
    m_value = newValue;
    // qDebug() << "change value";
    emit valueChanged();
}

void Cell::setValueWithoutSignal(const QString &value)
{
    if (m_value == value)
        return;
    m_value = value;
}
