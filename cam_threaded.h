#ifndef CAM_THREADED_H
#define CAM_THREADED_H

#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>

#include "opencv2/highgui/highgui.hpp"
#include <librealsense2/rs.hpp> // Include RealSense Cross Platform API

class Cam_Threaded{

public:

    void init();
    void close();

    void update(void);

    std::mutex g_lockData;
    std::mutex g_waitforimage;

    int frame_number;
    int frame_time;
    cv::Mat frameL;


private:

    bool ready;

    int frame_time_tmp;
    int frame_number_tmp;
    cv::Mat frameL_tmp;

    rs2::pipeline rs_cam;

    std::thread thread_cam;
    bool exitCamThread = false;
    void workerThread(void);

};

#endif // CAM_THREADED_H
