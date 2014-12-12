#ifndef CTV_SET_H_
#define CTV_SET_H_

class CTvSet
{
public:
    CTvSet()
        :m_turnedOn(false)
        ,m_channel(0)
    {};
    ~CTvSet(){};

    bool IsTurnedOn() const;
    unsigned int GetChannel() const;

    bool TurnOn();

private:
    bool m_turnedOn;
    unsigned int m_channel;
};

#endif //CTV_SET_H_
