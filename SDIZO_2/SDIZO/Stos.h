#pragma once
#include "ElementListy.h"

class Stos {

private:
    ElementListy *s;

public:

    Stos();

    ~Stos();

    bool empty();

    int top();

    void pop();

    void push(int w);
};

