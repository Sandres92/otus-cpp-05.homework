#include <string>

#include "IIimporter.h"
#include "../Canvas/ICanvasModel.h"

namespace otus
{
    class TestIimporter : public IIimporter
    {
    public:
        ICanvasModel &Import(const std::string &fileName) override;
    };
}