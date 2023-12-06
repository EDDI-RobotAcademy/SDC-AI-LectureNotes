//
// Created by eddi on 23. 12. 1.
//

#ifndef CLASS_TEST_VECTOR_H
#define CLASS_TEST_VECTOR_H


#include <string>

class Vector {
private:
   const int VECTOR_MIN = -9;
   const int VECTOR_MAX = 9;
    int x;
    int y;
    int z;


public:
   Vector();
   void rollVector();
    int getVectorX();
    int getVectorY();
    int getVectorZ();
    void addVector(Vector, Vector);
    void subVector(Vector, Vector);
//   ~Vector();


};


#endif //CLASS_TEST_VECTOR_H
