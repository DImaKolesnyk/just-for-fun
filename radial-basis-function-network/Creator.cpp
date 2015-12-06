//
// Created by dima on 05.12.15.
//
#include "Creator.hpp"

Creator::Creator(){

}

Net * Creator::learn(NetBuilder builder, const Data &data ) {

    builder.learn(data);
    return builder.get();
}

