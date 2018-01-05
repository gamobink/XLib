#ifndef _XCHAIN_H_
#define _XCHAIN_H_

#include "XLib.h"
#include "XNode.h"

template<class T,class TBase = XNode>
class Record : public XNode2<T,TBase>
{

};

//////////////////////////////////////////////////////////////////////////
//��Ϣ/��¼��
//1����Ϣֻ�������Ӳ�����ɾ��
//2����Ϣ������������Ҳ����ͨ����֤�����ӣ���Ҫ���ݾ���Ӧ��
//
//��ע��
//1��ÿ���ڵ�ͨ���ǶԳƼ��ܽ���ͨѶ��Կ����Կ�㷨����ʹ����Կ����Կ�㷨����ͨѶ
//2���ڵ���Ϣ����ʹ��DHT����ʵ�ֲַ�ʽ�洢���������������Ǿ�����ȶ��Ľ�׳��
//3������ʵ���������е���Ϣ�ķֲ�ʽ��ȫ�洢

//��¼��˭��ʲôʱ������ʲô��
struct RecordInfo //SIZE=256�ֽ�
{
	union
	{
		char Reserved[251];
		struct
		{
			union
			{
				unsigned short ver; //�汾
				struct  
				{
					unsigned char mver; //���汾
					unsigned char cver;	//�Ӱ汾
				};
			};
			union
			{
				unsigned short type; //����
				struct  
				{
					unsigned char mtype; //������
					unsigned char ctype; //������
				};
			};
			int date; //���� +/-YYYY-MM-DD 20160720��2016-7-20��
			unsigned int time; //ʱ�� HH:mm:SS sss 091516614��9:15:16 614��
			char who[32]; //hash ˭
			char what[32]; //hash ʲô
		};
	};
	unsigned int len; //���ݳ���
	char data[1]; //���� ��
};

//////////////////////////////////////////////////////////////////////////
//���ڼ�ֵ���������ɵĿ���֤�Ĳ��ɸ��ĵ���Ϣ���磬һ�ֹ���������
//
//�ڵ�
//1��ÿ���ڵ㶼�ǶԵȵ�
//2��ÿ���ڵ�Ĵ�ʼ��Ϣ����0
//3��ÿ���ڵ㶼Ҫ�洢�ڽ��ڵ���Ϣ��DHT����ʵ�֣�
//4��ÿ���ڵ㶼����������ˮ��Ϣ
//5��ÿ���ڵ㶼ҪУ��ÿ����ˮ��Ϣ�ĺϷ���
//6��һ��ʼÿ���ڵ��ֵ��0�����Ų����ʱ����ۻ��������ض��㷨��ʼΪ�������縶���Ľڵ����ɺ����ļ�ֵ�����˼�ֵ�Ϳ��Խ��м�ֵ������
//	�����磺�����ڵ�һ��ʼ�������������ֵ��Ȼ��ַ���ֵ��ȥ���ȷַ��������м�ֵ֮���ٴ�����ֵ��ʼ�ַ���
//��ע��
//1��ʵ������Ϣ����ʵ��ȫ�ɿ�
//2��ʵ������Ϣ�ķֲ�ʽ�洢
//3��ʵ���������ȥ���Ļ������Ҹ����ȶ���׳�������κα������ĵ���/��֯���ƻ�
//
//������
//1�������ڵ������һ�����õ�����֯����ҵ/��ҵ/����/����/��������֯/ȫ������֯�ȣ���
//	ÿ���ڵ����ʹ����ʵ�еĸ����ʲ���Ѻ������֯������֯���ݵ�ѺƷ�ļ�ֵ������ýڵ���ȼ�ֵ�����ּ�ֵ��
//	������ʵ������ʵ����������Ļ�ͨ���湲�٣���������ʵ�����ּ�ֵ���磬������������ÿ���˵���Ϣ���������ģ�ÿ���ڵ��ֶ��ǹ����ģ�����һ����������硣
//

//////////////////////////////////////////////////////////////////////////
//�������Ų��ɸ��ĵ���Ϣ/��¼����һ��˽��������
//
//���ڵ�
//1����¼���нڵ�
//2��ֱ�Ӹ��ڵ�������Ϣ�����Ӽ�ֵ�����ݣ�������ڵ�A����100����
//3������¼��ˮ��Ϣ
//
//��¼�ڵ�
//1����¼��ˮ��Ϣ���ֲ�ʽ��¼��ˮ��Ϣ���������нڵ㶼��������ˮ��Ϣ�����Ի���DHT����ʵ�֣�
//2��У��ÿ����ˮ��Ϣ�ĺϷ���
//
//��ͨ�ڵ�
//1��������ˮ��Ϣ����ˮ��Ϣ��Ҫͨ����¼�ڵ��ȷ�ϣ�
//
//��ע��
//1��ʵ������Ϣ����ʵ��ȫ�ɿ�
//2��ʵ������Ϣ�ķֲ�ʽ�洢�����������ȥ���Ļ�����ʹ���ķ�����崻������˸��ڵ�Ĺ���2�⣬�������綼���������е�
//

//////////////////////////////////////////////////////////////////////////
//Э��

class AuthenticRecord : Record<AuthenticRecord,RecordInfo>
{
public:
};

//��Ϣ������������¼Ա��
class AuthenticRecorder
{
protected:
	AuthenticRecord m_RecordChain;

public:
	//����ڵ���Ϣ��¼
	virtual void LoadRecord()
	{

	}


protected:
	//�յ�һ����Ϣ��¼
	virtual void OnReceiveRecord(RecordInfo r)
	{

	}

	//����һ����Ϣ��¼
	virtual void OnSendRecord(RecordInfo r)
	{

	}
};

#endif//_XCHAIN_H_