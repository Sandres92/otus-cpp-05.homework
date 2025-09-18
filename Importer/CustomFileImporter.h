#include <string>

#include "IIimporter.h"
#include "../Canvas/ICanvasModel.h"

namespace otus
{
    /**
     * @brief Class (Interface) importer from custom format file
     *
     */
    class CustomFileImporter : public IIimporter
    {
    public:
        CustomFileImporter() = default;
        ~CustomFileImporter() = default;

        ICanvasModel *Import(const std::string &fileName) override;
    };
}