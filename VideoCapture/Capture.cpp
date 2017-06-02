#include "opencv2\highgui\highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	VideoCapture cap("E:\\MOVIES\\Bahubali1.mkv");
	if (!cap.isOpened())
	{
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	double fps = cap.get(CV_CAP_PROP_FPS);
	cout << "Frame per seconds: " << fps << endl;
	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE);
	while (1)
	{
		Mat frame;
		bool bSuccess = cap.read(frame);
		if (!bSuccess)
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}

		imshow("MyVideo",frame);
		if (waitKey(30) == 27)
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;
}