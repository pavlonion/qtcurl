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

    QUrl url("http://targoman.com?id=42");

    QtCUrl::Options opt;
    opt[CURLOPT_URL] = url;
    opt[CURLOPT_POST] = true;
    opt[CURLOPT_FOLLOWLOCATION] = true;
    opt[CURLOPT_FAILONERROR] = true;
    QStringList headers = {
        {"Accept  text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"},
        {"Accept-Encoding	gzip, deflate"},
        {"Accept-Language	ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3"},
        {"User-Agent	Mozilla/5.0 (X11; Linux x86_64; rv:20.0) Gecko/20100101 Firefox/20.0"}
    };
    opt[CURLOPT_HTTPHEADER] = headers;

    cUrl.mime_addData("username", "aaa");
    cUrl.mime_addData("password", "bbb");
    cUrl.mime_addFile("file_1", "../../README.md");
    cUrl.mime_addFile("file_2", "../../LICENSE");

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
