//
// Created by dima on 05.12.15.
//
#include "Creator.hpp"

Creator::Creator() : net(nullptr){

}

Net * Creator::learn(const NetBuilder &builder, const Data &data ) {

    net = builder.learn(data);
    return builder.get();
}

