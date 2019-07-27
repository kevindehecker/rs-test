#include "cam.h"
#include "opencv2/imgproc/imgproc.hpp"
#include <librealsense2/rsutil.h>

using namespace cv;
using namespace std;

void Cam::update(void) {
	rs2::frameset fs;
	fs = cam.wait_for_frames();
	frameL = Mat(Size(848, 480), CV_8UC1, const_cast<void *>(fs.get_infrared_frame(1).get_data()), Mat::AUTO_STEP);
	usleep(16666);
}

void Cam::init() {
	rs2::config cfg;
	cfg.enable_device_from_file("/media/houjebek/Kak/pats/cool_logging/test.bag");
	cam.start(cfg);
	dev = cam.get_active_profile().get_device();
	static_cast<rs2::playback>(dev).set_real_time(false);
}

void Cam::close() {
	cam.stop(); // this deadlocks if set_real_time was set to false!
}

