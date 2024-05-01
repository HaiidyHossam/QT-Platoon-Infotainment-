#ifndef ENGINECONFIGRATION_H
#define ENGINECONFIGRATION_H

#include <QObject>

class EngineConfigration: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int engineRPM READ engineRPM WRITE setEngineRPM NOTIFY nameChanged);
public:
    EngineConfigration();
    void setEngineRPM(int temp);
    int engineRPM() const;
signals:
    void engineRPMChanged();
private:
    int m_engineRPM;
    int m_speed;
    bool isAccelerating;
    bool isBraking;
};

#endif // ENGINECONFIGRATION_H
