#ifndef  _ZJY_SIMPLESOCKET_H_
#define  _ZJY_SIMPLESOCKET_H_
#include <winsock2.h>
#include <string>

class sockerr {
  int  m_err;
public:
  //出错码初始化
  sockerr (int e): m_err (e) {}
  int errnum () const { return m_err; }
  //出错描述
  const char* errstr () const;
};

class CSimpleSocket
{
public:
	CSimpleSocket():m_Socket(INVALID_SOCKET) {}
	bool Connect(const char* host, unsigned short port);
	bool Init();
	void Close();
	void Send(const char* data, int len);
	void Read(std::string &buf);
private:
	SOCKET m_Socket; 
};

#endif
