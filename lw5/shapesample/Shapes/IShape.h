#ifndef ISHAPE_H_
#define ISHAPE_H_

#include <string>

class IShape
{
public:
	virtual ~IShape() {};
	virtual double GetArea() const = 0;
	virtual double GetPerimiter() const = 0;
	virtual std::string ToString() const = 0;
};

#endif //ISHAPE_H_
