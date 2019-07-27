#ifndef CAM_H
#define CAM_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "opencv2/highgui/highgui.hpp"
#include <librealsense2/rs.hpp>

class Cam{

public:

    void init();
    void close();
    void update();

    cv::Mat frameL;

private:
    rs2::device dev;
    rs2::pipeline cam;
};

#endif // CAM_H
