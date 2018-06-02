#include "cam_threaded.h"

using namespace cv;
using namespace std;

void Cam_Threaded::update(void) {
    if (!ready) {
        std::cout << "Waiting for realsense..." << std::endl;
        while (!ready)
            usleep(1000);
    }

    g_waitforimage.lock();
    g_lockData.lock();
    frameL = frameL_tmp.clone();
    frame_number = frame_number_tmp;
    frame_time = frame_time_tmp;
    g_lockData.unlock();
}

void Cam_Threaded::init() {
    rs2::config cfg;
    cfg.disable_all_streams();
    cfg.enable_stream(RS2_STREAM_INFRARED, 1, 848, 480, RS2_FORMAT_Y8, 60);
    cfg.enable_stream(RS2_STREAM_INFRARED, 2, 848, 480, RS2_FORMAT_Y8, 60);

    rs_cam.start(cfg);
    thread_cam = std::thread(&Cam_Threaded::workerThread,this);
}

void Cam_Threaded::workerThread(void) {

    while (!exitCamThread) {

        rs2::frameset frame = rs_cam.wait_for_frames();

        g_lockData.lock();
        frame_time_tmp = frame.get_timestamp();
        frame_number_tmp = frame.get_frame_number();
        frameL_tmp = Mat(Size (848, 480), CV_8UC1, (void*)frame.get_infrared_frame(1).get_data(), Mat::AUTO_STEP);
        g_lockData.unlock();

        g_waitforimage.unlock();
        ready = true;

    }
    usleep(1000);
}

void Cam_Threaded::close() {
    exitCamThread = true;
    g_lockData.unlock();
    thread_cam.join();
}
