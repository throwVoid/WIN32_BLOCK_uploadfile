========================================================================
    使用帮助文档
========================================================================

1.定义一个UploadFile对象
2.使用CreateSendFile这个工厂方法返回ISendFileInterface*类型对象
3.你可以直接定义一个ISendFileInterface*指针来接收该返回值，通过多态实现功能；也可以定义一个CFileClient*来接收该返回值
4.ISendFileInterface接口中函数注释
  4.1 ChoseFile函数
  返回值：出错返回0，正常返回文件大小
  参数1：文件名
  参数2：自己命名的文件类型

  4.2 Connect函数
  返回值：返回连接状态，true/false
  参数1：指定对端的地址。
  参数2：端口

  4.3 SendFile函数
  返回值：0-发送完成，-1出错
  参数：PTransInfo，记录文件上传状态，其中PTransInfo定义如下
  typedef struct {
	unsigned int	uploaded;	//已经上传的字节数
	bool			finished;	//上传是否完成
}TransInfo,*PTransInfo;
5.传输完成后，使用DeleteSendFile删除创建的ISendFileInterface*对象