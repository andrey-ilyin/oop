#include "CTvSet.h"

bool CTvSet::IsTurnedOn() const
{
    return m_turnedOn;
}

unsigned int CTvSet::GetChannel() const
{
    return m_channel;
}

bool CTvSet::TurnOn()
{    
    m_turnedOn = true;
    m_channel = 1;
    return true;
}
