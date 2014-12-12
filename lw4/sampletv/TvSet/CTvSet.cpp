#include "CTvSet.h"

bool CTvSet::IsTurnedOn() const
{
    return m_turnedOn;
}

unsigned int CTvSet::GetChannel() const
{
    return m_turnedOn ? m_channel : 0;
}

bool CTvSet::SetChannel(unsigned channel)
{
    m_channel = channel;
    return true;
}

bool CTvSet::TurnOn()
{    
    m_turnedOn = true;
    return true;
}

bool CTvSet::TurnOff()
{
    m_turnedOn = false;
    return true;
}
