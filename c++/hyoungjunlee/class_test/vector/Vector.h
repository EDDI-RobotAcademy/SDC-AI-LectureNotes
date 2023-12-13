//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_VECTOR_H
#define CLASS_TEST_VECTOR_H


class Vector {
private:
    int x=10;
    int y=10;
    int z=10;
public:
    Vector();
    int getxVector();
    int getyVector();
    int getzVector();
    int plusxVector();
    int plusyVector();
    int pluszVector();
    ~Vector();
};


#endif //CLASS_TEST_VECTOR_H
