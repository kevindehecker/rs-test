#include "cam.h"

using namespace cv;
using namespace std;

void Cam::init() {
    rs2::config cfg;

    cfg.disable_all_streams();
    cfg.enable_stream(RS2_STREAM_INFRARED, 1, 848, 480, RS2_FORMAT_Y8, 60);

    rs_cam.start(cfg);
}

void Cam::close() {

}

void Cam::update() {
    rs2::frameset frame = rs_cam.wait_for_frames();
    frameL = Mat(Size(848, 480), CV_8UC1, (void*)frame.get_infrared_frame(1).get_data(), Mat::AUTO_STEP);
    frame_number = frame.get_frame_number();
    frame_time = frame.get_timestamp() ;
}
