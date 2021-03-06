//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "TensorUtils.hpp"

namespace armnnUtils
{

armnn::TensorShape GetTensorShape(unsigned int numberOfBatches,
                                  unsigned int numberOfChannels,
                                  unsigned int height,
                                  unsigned int width,
                                  const armnn::DataLayout dataLayout)
{
    switch (dataLayout)
    {
        case armnn::DataLayout::NCHW:
            return armnn::TensorShape({numberOfBatches, numberOfChannels, height, width});
        case armnn::DataLayout::NHWC:
            return armnn::TensorShape({numberOfBatches, height, width, numberOfChannels});
        default:
            throw armnn::InvalidArgumentException("Unknown data layout ["
                                                  + std::to_string(static_cast<int>(dataLayout)) +
                                                  "]", CHECK_LOCATION());
    }
}

armnn::TensorInfo GetTensorInfo(unsigned int numberOfBatches,
                                unsigned int numberOfChannels,
                                unsigned int height,
                                unsigned int width,
                                const armnn::DataLayout dataLayout,
                                const armnn::DataType dataType)
{
    switch (dataLayout)
    {
        case armnn::DataLayout::NCHW:
            return armnn::TensorInfo({numberOfBatches, numberOfChannels, height, width}, dataType);
        case armnn::DataLayout::NHWC:
            return armnn::TensorInfo({numberOfBatches, height, width, numberOfChannels}, dataType);
        default:
            throw armnn::InvalidArgumentException("Unknown data layout ["
                                                  + std::to_string(static_cast<int>(dataLayout)) +
                                                  "]", CHECK_LOCATION());
    }
}

}
