#ifndef CAM_H
#define CAM_H

#include "opencv2/highgui/highgui.hpp"
#include <librealsense2/rs.hpp>

class Cam{

public:

    void init();
    void close();
    void update();

    int frame_number;
    float frame_time;
    cv::Mat frameL;

private:

    rs2::pipeline rs_cam;

};

#endif // CAM_H
