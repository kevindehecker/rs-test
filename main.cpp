#include "cam.h"
#include "cam_threaded.h"

using namespace cv;
using namespace std;

#if 0 // change to switch between threaded and non threaded
Cam cam;
#else
Cam_Threaded cam;
#endif

int main( int argc, char **argv )
{

    cam.init();

    unsigned char key = 0;
    while (key != 27) {
        cam.update();

        std::cout << cam.frame_number << ": " << cam.frame_time << std::endl;
        imshow("test", cam.frameL);
        key = waitKey(1);
    }

    cv::destroyAllWindows();
    cam.close();

    return 0;
}
