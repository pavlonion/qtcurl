/*
 * @author Kambiz Zandi <kambizzandi@gmail.com>
 */

#include "QtCUrl.h"
#include <QUrl>
#include <QDebug>

int main(int argc, char** argv) {
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QtCUrl cUrl;
    cUrl.setTextCodec("Windows-1251");

//    QUrl url("http://targoman.com?id=42");
    QUrl url("http://localhost:10000/rest/v1/ping");

    QtCUrl::Options opt;
    opt[CURLOPT_URL] = url.toString();
//    opt[CURLOPT_POST] = true;
//    opt[CURLOPT_CUSTOMREQUEST] = "GET";
    opt[CURLOPT_FOLLOWLOCATION] = true;
    opt[CURLOPT_FAILONERROR] = true;
//    QStringList headers = {
//        { "Content-Type: application/json" },
//        { "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8" },
//        { "Accept-Encoding: gzip, deflate" },
//        { "Accept-Language: ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3" },
//        { "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:20.0) Gecko/20100101 Firefox/20.0" },
//    };
//    opt[CURLOPT_HTTPHEADER] = headers;

    cUrl.mime_addFile("file_1", "../../example/SAMPLE1");
    cUrl.mime_addFile("file_2", "../../example/SAMPLE2");
    cUrl.mime_addData("username", "aaa");
    cUrl.mime_addData("password", "bbb");

    QString result = cUrl.exec(opt);

    if (cUrl.lastError().isOk()) {
        qDebug() << result;
    }
    else {
        qDebug() << QString("Error: %1\nBuffer: %2").arg(
                        cUrl.lastError().text()).arg(
                        cUrl.errorBuffer());
    }
    return 0;
}
