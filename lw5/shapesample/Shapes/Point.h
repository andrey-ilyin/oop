#ifndef POINT_H_
#define POINT_H_

#include "IShape.h"

class CPoint : public IShape
{
public:
	CPoint();
	CPoint(double x, double y);
	double GetX() const;
	double GetY() const;
    
    double GetArea() const override final;
    double GetPerimiter() const override final;
    std::string ToString() const override;
private:
	double m_x, m_y;
};

#endif //POINT_H_
