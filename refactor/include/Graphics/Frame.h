#pragma once

#include <string>

#include "Dim.h"
#include "Tuple.h"

namespace ns
{

class Frame
{
    public:
        Frame();
        virtual ~Frame();

        void setAspectRatio(const ns::Dim2<int>& dimensions);
        void setDimensions(const ns::Dim2<int>& dimensions);
        void setWidth(const int& width);
        void setHeight(const int& height);

        ns::Tuple2<int> getAspectRatio() const;
        ns::Dim2<int> getDimensions() const;
        int getWidth() const;
        int getHeight() const;

        void rebuildFrame();

    protected:
        ns::Dim2<int> dimensions;
};

}
