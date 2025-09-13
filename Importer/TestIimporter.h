#include <string>

#include "IIimporter.h"
#include "../CanvasModel.h"

namespace otus
{
    class TestIimporter : public IIimporter
    {
    public:
        CanvasModel &Import(const std::string &fileName) override;
    };
}