#include "Frame.h"

namespace ns
{

    Frame::Frame()
        : dimensions{},
          aspectRatio{},
          lockAspectRatio{false}
    { }

    Frame::Frame(ns::Dim2<int> dimensions)
        : dimensions{dimensions},
          aspectRatio{0},
          lockAspectRatio{false}
    { }


    Frame::~Frame()
    { }

    void Frame::setAspectRatio(const ns::Dim2<int>& dim)
    { 
        aspectRatio = dim.w / static_cast<float>(dim.h);
    }

    void Frame::setDimensions(const ns::Dim2<int>& dim)
    { 
        dimensions = dimensions;
    }

    void Frame::setWidth(const int& width)
    { 
        dimensions.w = width;
    }

    void Frame::setHeight(const int& height)
    { 
        dimensions.h = height;
    }

    float Frame::getAspectRatio() const
    { 
        return aspectRatio;
    }

    ns::Dim2<int> Frame::getDimensions() const
    { 
        return dimensions;
    }

    int Frame::getWidth() const
    { 
        return dimensions.w;
    }

    int Frame::getHeight() const
    { 
        return dimensions.h;
    }

    void Frame::rebuildFrame()
    {

    }

}
