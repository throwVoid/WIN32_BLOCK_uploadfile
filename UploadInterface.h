#ifndef	_ZJY_UPLOADINTERFACE_H_
#define _ZJY_UPLOADINTERFACE_H_


typedef struct {
	unsigned int	uploaded;	//�Ѿ��ϴ����ֽ���
	bool			finished;
}TransInfo,*PTransInfo;

struct ISendFileInterface {
	virtual ~ISendFileInterface(){};

	//return>0:file size
	//return=0:zero byte file or error
	virtual unsigned int ChoseFile(const char *file,int type)=0;
	
	//���ӷ�����
	virtual bool Connect(const char *host,unsigned short port)=0;
	
	//��������
	//-1:socket ����
	//0:�ϴ����
	virtual int SendFile(PTransInfo info)=0;

	virtual void Stop()=0;

	virtual const char *GetError()=0;
};


#endif
