#pragma once

#include "Dim.h"

namespace ns
{

class Frame
{
    public:
        Frame();
        Frame(ns::Dim2<int> dimenstions);
        virtual ~Frame();

        void setAspectRatio(const ns::Dim2<int>& dim);
        void setDimensions(const ns::Dim2<int>& dim);
        void setWidth(const int& width);
        void setHeight(const int& height);

        float getAspectRatio() const;
        ns::Dim2<int> getDimensions() const;
        int getWidth() const;
        int getHeight() const;

        void rebuildFrame();

    protected:
        ns::Dim2<int> dimensions;
        float aspectRatio;
        bool lockAspectRatio;
};

}
