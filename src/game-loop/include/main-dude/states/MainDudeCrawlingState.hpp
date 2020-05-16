#pragma once

#include "main-dude/states/MainDudeBaseState.hpp"

class MainDudeCrawling : public MainDudeBaseState
{
public:

    MainDudeBaseState* update(MainDude&, uint32_t delta_time_ms) override;
    void enter(MainDude&) override;
};