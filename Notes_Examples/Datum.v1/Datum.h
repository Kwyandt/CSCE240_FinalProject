#ifndef DATUM_H
#define DATUM_H
#include <cstdlib>

class Datum
{
    public:
        Datum();
        Datum(float);
        Datum(const Datum&);
        ~Datum();

        float getData() const;
        void setData(float);

        void setNext(Datum &);
        Datum * getNext() const;
    public:
        float data;
        Datum *next;
};

#endif // DATUM_H
