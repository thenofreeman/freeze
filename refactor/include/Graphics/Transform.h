#pragma once

#include "Coor.h"
#include "Dim.h"

namespace ns
{

class Transform2
{
    public:
        Transform2();
        virtual ~Transform2();

        void setPosition(const ns::Coor2<int>& pos);
        void setDimensions(const ns::Dim2<int>& dim);

    private:
        ns::Coor2<int> position;
        ns::Dim2<int> dimensions;

};

}