//
// Created by Andrii PAVLOV on 2019-12-19.
//

#ifndef NIBBLER_SNAKEBODYCOLOR_H
#define NIBBLER_SNAKEBODYCOLOR_H

struct SnakeBodyColor {
    enum Color {
        RED = 0xff0000, LIGHTRED = 0xaa0000, BLUE = 0x0000ff, CYAN = 0x0000aa
    };
    uint32_t  head;
    uint32_t  body;
};

#endif //NIBBLER_SNAKEBODYCOLOR_H
