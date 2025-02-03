#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>

#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <aws/s3/model/GetObjectRequest.h>
#include <fstream>

const Aws::String BUCKET_NAME = "qt-aws-s3-test-seoul";
const Aws::String OBJECT_KEY = "test-file.txt";
const Aws::String FILE_PATH = "/Users/carima/Documents/Programming/QT/test-app/testfolder/test-file.txt";

class AwsS3Manager {
public:
    AwsS3Manager() {
        Aws::SDKOptions options;
        Aws::InitAPI(options);
    }

    ~AwsS3Manager() {
        Aws::SDKOptions options;
        Aws::ShutdownAPI(options);
    }

    bool uploadFile(const Aws::String &bucket, const Aws::String &key, const Aws::String &filePath) {
        Aws::Client::ClientConfiguration config;
        config.region = "ap-northeast-2";
        config.endpointOverride = "s3.ap-northeast-2.amazonaws.com";
        Aws::S3::S3Client s3_client(config);

        Aws::S3::Model::PutObjectRequest request;
        request.SetBucket(bucket);
        request.SetKey(key);

        auto input_data = Aws::MakeShared<Aws::FStream>("UploadStream", filePath.c_str(), std::ios_base::in | std::ios_base::binary);
        if (!input_data->good()) {
            qDebug() << "Failed to open file: " << filePath.c_str();
            return false;
        }

        request.SetBody(input_data);
        auto outcome = s3_client.PutObject(request);

        if (outcome.IsSuccess()) {
            qDebug() << "Successfully uploaded " << key.c_str();
            return true;
        } else {
            qDebug() << "Upload failed: " << outcome.GetError().GetMessage().c_str();
            return false;
        }
    }

    bool downloadFile(const Aws::String &bucket, const Aws::String &key, const Aws::String &outputFilePath) {
        Aws::Client::ClientConfiguration config;
        config.region = "ap-northeast-2";
        config.endpointOverride = "s3.ap-northeast-2.amazonaws.com";
        Aws::S3::S3Client s3_client(config);

        Aws::S3::Model::GetObjectRequest request;
        request.SetBucket(bucket);
        request.SetKey(key);

        auto outcome = s3_client.GetObject(request);

        if (outcome.IsSuccess()) {
            std::ofstream outputFile(outputFilePath, std::ios::binary);
            outputFile << outcome.GetResult().GetBody().rdbuf();
            qDebug() << "Successfully downloaded " << key.c_str();
            return true;
        } else {
            qDebug() << "Download failed: " << outcome.GetError().GetMessage().c_str();
            return false;
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Qt - AWS Test");

    QPushButton uploadButton("Upload File");
    QPushButton downloadButton("Download File");

    QVBoxLayout layout;
    layout.addWidget(&uploadButton);
    layout.addWidget(&downloadButton);
    window.setLayout(&layout);

    AwsS3Manager awsManager;

    QObject::connect(&uploadButton, &QPushButton::clicked, [&]() {
        awsManager.uploadFile(BUCKET_NAME, OBJECT_KEY, FILE_PATH);
    });

    QObject::connect(&downloadButton, &QPushButton::clicked, [&]() {
        awsManager.downloadFile(BUCKET_NAME, OBJECT_KEY, "/path/to/downloaded/file.txt");
    });

    window.show();
    return app.exec();
}
