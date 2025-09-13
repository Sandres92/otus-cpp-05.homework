#include "../CanvasModel.h"
#include <string>

namespace otus
{
    class IIimporter
    {
    public:
        virtual CanvasModel &Import(const std::string &fileName) = 0;
    };
}