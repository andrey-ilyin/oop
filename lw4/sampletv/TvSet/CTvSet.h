#ifndef CTV_SET_H_
#define CTV_SET_H_

class CTvSet
{
public:
    CTvSet(){};
    ~CTvSet(){};

    bool IsTurnedOn() const;
    unsigned int GetChannel() const;
};

#endif //CTV_SET_H_
