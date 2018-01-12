#ifndef FEATURE_H_
#define FEATURE_H_

#include "FullSystem/HessianBlocksh"

namespace fdso {

// Feature
// 表示点特征，它由特征提取算法提取，存放于Frame中
// 如果一个特点被三角化，则产生对应的地图点

struct Feature
{
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    Feature(
        const Eigen::Vector2d& pixel,
        const int& level = 0,
        const double& score = 0
    ) : _pixel(pixel), _level(level), _score(score) {}

    Eigen::Vector2d _pixel = Vector2d(0, 0);           // 图像位置
    double   _depth = -1;
    Eigen::Vector3d _normal = Vector3d(0, 0, 0);   // 归一化坐标
    int      _level = -1;                                   // 特征点所属金字塔层数
    double   _angle = 0;                                // 旋转角（2D图像中使用）
    cv::Mat      _desc = cv::Mat(1, 32, CV_8UC1); // ORB 描述子
    FrameHessian*   _frame = nullptr;                      // 所属的帧，一个特征只属于一个帧
    // 一个特征只能对应到一个地图点，但一个地图点可对应多个帧

    bool     _bad = false;                                  // bad flag
    double   _score = 0;                                // 分数
};

}

#endif // FEATURE_H_