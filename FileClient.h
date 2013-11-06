#ifndef	_ZJY_FILECLIENT_H_
#define _ZJY_FILECLIENT_H_
#include <string>
#include "UploadInterface.h"

#include "SimpleSocket.h"
using std::string;

struct FileInfo {
	string short_name;
	DWORD file_size;
	unsigned int writed;
	FILE *fp;
	int type;
	FileInfo():file_size(0), writed(0), fp(0), type(0) {}
	~FileInfo() {
		if(fp)
			fclose(fp);
	}
	//文件传输是否完成
	bool Finish() {
		return writed == file_size;
	}
	//文件流是否已经被赋值
	bool Valued() {
		return fp != 0;
	}
	//从文件中读取nsize字节，nsize返回实际字节，函数返回首地址
	const char *read(int &nsize);
};





class CFileClient:public ISendFileInterface {
public:
	CFileClient():m_stop(true) {}
	virtual ~CFileClient() {}
	virtual const char *GetError() {
		return m_error.c_str();
	}

	virtual unsigned int ChoseFile(const char *name, int type);
	virtual bool Connect(const char *host, unsigned short port);
	virtual int SendFile(PTransInfo info);
	virtual void Stop() {
		m_stop=true;
	}	
private:
	FileInfo m_file;
	string m_error;
	CSimpleSocket m_sock;
	bool	m_stop;
};
#endif