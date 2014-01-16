/**
 * $URL: svn+ssh://tserver/var/svn/cps/trunk/src/cpp/lib/qtcurl/QtCUrl.h $
 * $Author: romanenko $
 * $Date: 2013-07-12 08:57:30 +0400 (Пт, 12 июл 2013) $
 * $Rev: 451 $
 */

#ifndef QTCURL_H
#define QTCURL_H

#include <curl/curl.h>
#include <QHash>
#include <QVariant>
#include <QLinkedList>
class QTextCodec;

class QtCUrl {
public:
	typedef QHash<CURLoption, QVariant> Options;
	typedef QHashIterator<CURLoption, QVariant> OptionsIterator;
	typedef int (*WriterPtr)(char*, size_t, size_t, std::string*);

	class Code {
	public:
		Code(CURLcode code = CURLE_OK): _code(code) {}
		QString text() { return curl_easy_strerror(_code); }
		inline CURLcode code() { return _code; }
		inline bool isOk() { return _code == CURLE_OK; }

	private:
		CURLcode _code;
	};

	QtCUrl();
	virtual ~QtCUrl();

	QString exec(Options& opt);
	inline Code lastError() { return _lastCode; }
	QString errorBuffer() { return _errorBuffer; }
	void setTextCodec(const char* codecName);
	void setTextCodec(QTextCodec* codec);



protected:
	void setOptions(Options& opt);

private:
	CURL* _curl;
	char* _errorBuffer;
	std::string _buffrer;
	Code _lastCode;
	QTextCodec* _textCodec;
	QLinkedList<curl_slist*> _slist;
};

Q_DECLARE_METATYPE(QtCUrl::WriterPtr)
Q_DECLARE_METATYPE(std::string*)
Q_DECLARE_METATYPE(char*)

#endif // QTCURL_H
