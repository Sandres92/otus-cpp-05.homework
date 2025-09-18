#include <string>

#include "IIimporter.h"
#include "../Canvas/ICanvasModel.h"

namespace otus
{
    /**
     * @brief Class (Interface) test importer
     *
     */
    class TestIimporter : public IIimporter
    {
    public:
        TestIimporter() = default;
        ~TestIimporter() = default;

        ICanvasModel *Import(const std::string &fileName) override;
    };
}
