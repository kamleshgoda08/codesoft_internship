#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Function to display the image
void displayImage(const string& windowName, const Mat& image) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, image);
}

int main() {
    Mat image;
    string imagePath;

    // Load Image
    cout << "Enter the path to the image: ";
    cin >> imagePath;
    image = imread(imagePath);

    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // Display Original Image
    displayImage("Original Image", image);

    // Menu for image processing options
    int choice;
    do {
        cout << "\nImage Processing Menu:\n";
        cout << "1. Convert to Grayscale\n";
        cout << "2. Apply Blur\n";
        cout << "3. Apply Sharpen\n";
        cout << "4. Adjust Brightness\n";
        cout << "5. Adjust Contrast\n";
        cout << "6. Crop Image\n";
        cout << "7. Resize Image\n";
        cout << "8. Save Image\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Mat processedImage = image.clone();

        switch (choice) {
            case 1: // Grayscale
                cvtColor(image, processedImage, COLOR_BGR2GRAY);
                break;
            case 2: // Blur
                GaussianBlur(image, processedImage, Size(15, 15), 0);
                break;
            case 3: // Sharpen
                Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
                filter2D(image, processedImage, -1, kernel);
                break;
            case 4: // Adjust Brightness
                int brightness;
                cout << "Enter brightness value (-100 to 100): ";
                cin >> brightness;
                processedImage = image + Scalar(brightness, brightness, brightness);
                break;
            case 5: // Adjust Contrast
                double contrast;
                cout << "Enter contrast value (1.0 to 3.0): ";
                cin >> contrast;
                processedImage = image * contrast;
                break;
            case 6: // Crop Image
                int x, y, width, height;
                cout << "Enter x, y, width, height: ";
                cin >> x >> y >> width >> height;
                processedImage = image(Rect(x, y, width, height));
                break;
            case 7: // Resize Image
                int newWidth, newHeight;
                cout << "Enter new width and height: ";
                cin >> newWidth >> newHeight;
                resize(image, processedImage, Size(newWidth, newHeight));
                break;
            case 8: // Save Image
                string savePath;
                cout << "Enter the path to save the image: ";
                cin >> savePath;
                imwrite(savePath, processedImage);
                cout << "Image saved successfully!\n";
                break;
            case 9: // Exit
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }

        if (choice >= 1 && choice <= 7) {
            displayImage("Processed Image", processedImage);
        }

    } while (choice != 9);

    return 0;
}