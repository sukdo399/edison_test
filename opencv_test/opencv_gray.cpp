#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;
int main( int argc, char** argv )
{
        char* imageName = argv[1];
        Mat image, gray_image;
        if( argc != 2 ) {
                printf( " No image data \n " );  return -1;
        }
	image = imread( imageName, 1 );
        cvtColor( image, gray_image, CV_BGR2GRAY );
        imwrite("result.jpg", gray_image );
        return 0;
}



