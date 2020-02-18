//
// Created by Administrator on 2019/8/8.
//

#ifndef HEADER_H
#define HEADER_H

#include <iostream>

static int count = 0;

class Test {
public:
    Test() {
        std::cout << " Test construct .  construct nums  is " << count << std::endl;
        count++;
    }

};

static Test t;


#endif //BOLG_H1_H
