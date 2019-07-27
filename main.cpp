#include <iostream>
#include "cam.h"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

unsigned char key = 0;
Cam cam;

void handle_key() {
    if (key == 27) { // set by an external ctrl-c
	return;
    }
    key = cv::waitKey(1);
    key = key & 0xff;
    if (key == 27) {  //esc
	return; // don't clear key, just exit
    }
    key=0;
}

int main( int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
    cam.init();

    while (key != 27) // ESC
    {
	cam.update();
	cv::imshow("Blah", cam.frameL);
	handle_key();
    }

    cv::destroyAllWindows();
    cam.close();
    return 0;
}
