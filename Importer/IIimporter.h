#include "../Canvas/CanvasModel.h"
#include <string>

namespace otus
{
    class IIimporter
    {
    public:
        virtual ICanvasModel &Import(const std::string &fileName) = 0;
    };
}