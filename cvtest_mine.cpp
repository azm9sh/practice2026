#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  cv::Mat image = cv::imread("./barbara.ppm", cv::IMREAD_ANYCOLOR);
  if (image.empty()) return EXIT_FAILURE;

  const int width = image.cols;
  const int height = image.rows;
  const int nc = image.channels();
  const int stride = image.step;

  std::cout << "width = " << width << ", ";
  std::cout << "height = " << height << std::endl;

  auto pixel = image.data;
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      int B = pixel[i * stride + j * nc + 0];
      int G = pixel[i * stride + j * nc + 1];
      int R = pixel[i * stride + j * nc + 2];

      // ミニ課題1自作
      pixel[i * stride + j * nc + 0] = cv::saturate_cast<uchar>(B * 2);
      pixel[i * stride + j * nc + 1] = cv::saturate_cast<uchar>(G * 2);
      pixel[i * stride + j * nc + 2] = cv::saturate_cast<uchar>(R * 2);
    }
  }
  cv::imshow("loaded image", image);

  cv::waitKey(0);
  return EXIT_SUCCESS;
}
