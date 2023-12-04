//
// Created by Honor on 04.12.2023.
//

#ifndef ABSTRACT_FACTORY_PRODUCTION_H
#define ABSTRACT_FACTORY_PRODUCTION_H

#include "OS.h"
#include "OSFactory.h"

namespace factories {
    class Production {
    public:
        static OS *createOS(OSFactory *factory);
    };
}

#endif //ABSTRACT_FACTORY_PRODUCTION_H
