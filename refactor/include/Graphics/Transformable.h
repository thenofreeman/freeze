#pragma once

#include "Transform.h"

class Transformable : public ns::Transform2
{
    public:
        virtual ~Transformable();

    protected:
        Transformable();


};