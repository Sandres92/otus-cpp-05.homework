#define BOOST_TEST_MODULE test_version

#include <iostream>

#include "lib.h"
#include <boost/test/unit_test.hpp>

#include "Canvas/ICanvasModel.h"
#include "Canvas/CanvasModel.h"

#include "Canvas/ICanvasView.h"
#include "Canvas/MockCanvasView.h"

#include "Canvas/CanvasController.h"

#include "GraphicPrimitives/GraphicPrimitiveType.h"
#include "GraphicPrimitives/Circle.h"

#include "Action/Action.h"

BOOST_AUTO_TEST_SUITE(test_editor)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_CASE(test_valid_sum)
{
    BOOST_CHECK(1 + 1 == 2);
}

BOOST_AUTO_TEST_CASE(test_action_1)
{
    otus::Action<int> action;
    int countInvoke = 0;
    auto id = action.AddFunction([&countInvoke](int value)
                                 { 
                                    ++value;
                                    ++ countInvoke; });

    if (id)
    {
        action.Invoke(5);
    }

    BOOST_CHECK(countInvoke == 1);
}

BOOST_AUTO_TEST_CASE(test_action_2)
{
    otus::Action<int> action;
    int countInvoke = 0;
    auto id = action.AddFunction([&countInvoke](int value)
                                 { 
                                    ++value;
                                    ++ countInvoke; });

    action.RemoveFunction(id);
    if (id)
    {
        action.Invoke(5);
    }

    BOOST_CHECK(countInvoke == 0);
}

BOOST_AUTO_TEST_CASE(test_canvas_model_1)
{
    otus::CustomUniquePtr<otus::ICanvasModel> canvasModel(new otus::CanvasModel());

    canvasModel.get()->AddPrimitive(new otus::Circle(1, 1, 5));

    BOOST_CHECK(canvasModel.get()->GetAllGraphicPrimitive().size() == 1);
}

BOOST_AUTO_TEST_CASE(test_canvas_model_2)
{
    otus::CustomUniquePtr<otus::ICanvasModel> canvasModel(new otus::CanvasModel());

    otus::Circle *circle = new otus::Circle(1, 1, 5);
    canvasModel.get()->AddPrimitive(circle);

    canvasModel.get()->RemovePrimitive(circle);

    BOOST_CHECK(canvasModel.get()->GetAllGraphicPrimitive().size() == 0);
}

BOOST_AUTO_TEST_CASE(test_canvas_view_1)
{
    otus::CustomSharedPtr<otus::ICanvasModel> canvasModel(new otus::CanvasModel());
    otus::CustomUniquePtr<otus::ICanvasView> canvasView(new otus::MockCanvasView(canvasModel));

    canvasModel.get()->Notify();

    const otus::MockCanvasView *mockCanvasView = dynamic_cast<const otus::MockCanvasView *>(canvasView.get());

    BOOST_CHECK(mockCanvasView->GetUpdateCount() == 1);

    canvasModel.get()->Notify();

    BOOST_CHECK(mockCanvasView->GetUpdateCount() == 2);
}

BOOST_AUTO_TEST_CASE(test_canvas_controller_1)
{
    otus::CustomSharedPtr<otus::ICanvasModel> canvasModel(new otus::CanvasModel());
    otus::CustomSharedPtr<otus::ICanvasView> canvasView(new otus::MockCanvasView(canvasModel));

    otus::CanvasController canvasController(canvasModel, canvasView);

    canvasController.CreateGraphicPrimitive(otus::GraphicPrimitiveType::Circle);

    BOOST_CHECK(canvasModel.get()->GetAllGraphicPrimitive().size() == 3);
}

BOOST_AUTO_TEST_SUITE_END()
