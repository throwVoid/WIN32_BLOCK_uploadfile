========================================================================
    ʹ�ð����ĵ�
========================================================================

1.����һ��UploadFile����
2.ʹ��CreateSendFile���������������ISendFileInterface*���Ͷ���
3.�����ֱ�Ӷ���һ��ISendFileInterface*ָ�������ո÷���ֵ��ͨ����̬ʵ�ֹ��ܣ�Ҳ���Զ���һ��CFileClient*�����ո÷���ֵ
4.ISendFileInterface�ӿ��к���ע��
  4.1 ChoseFile����
  ����ֵ��������0�����������ļ���С
  ����1���ļ���
  ����2���Լ��������ļ�����

  4.2 Connect����
  ����ֵ����������״̬��true/false
  ����1��ָ���Զ˵ĵ�ַ��
  ����2���˿�

  4.3 SendFile����
  ����ֵ��0-������ɣ�-1����
  ������PTransInfo����¼�ļ��ϴ�״̬������PTransInfo��������
  typedef struct {
	unsigned int	uploaded;	//�Ѿ��ϴ����ֽ���
	bool			finished;	//�ϴ��Ƿ����
}TransInfo,*PTransInfo;
5.������ɺ�ʹ��DeleteSendFileɾ��������ISendFileInterface*����