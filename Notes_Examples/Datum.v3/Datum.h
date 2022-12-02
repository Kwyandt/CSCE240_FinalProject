#ifndef DATUM_H
#define DATUM_H
#include <cstdlib>

class Datum
{
    public:
        Datum();
        Datum(float value = 0.0); //: data(value) {

//        }
        Datum(const Datum&);
        virtual ~Datum();

        float getData() const;
        void setData(float);

        void setNext(Datum &);
        Datum * getNext();
    public:
        float data;
        Datum *next;
};

#endif // DATUM_H
