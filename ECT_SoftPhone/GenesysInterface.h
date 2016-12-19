// GenesysInterface.h: interface for the CGenesysInterface class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GENESYSINTERFACE_H__4DE8FC64_BEF7_44B4_9988_3A06A77067E9__INCLUDED_)
#define AFX_GENESYSINTERFACE_H__4DE8FC64_BEF7_44B4_9988_3A06A77067E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CTIInterface.h"
//#include "AgentFormDlg.h"

class CGenesysInterface : public CCTIInterface
{
public:
  CGenesysInterface();
  virtual ~CGenesysInterface();
public:

  int Init();
  int Exit();
  int ConnectCTIServer(CString HostIP,long Port);
  void ReConnectTServer();

  //��ϯ����
  int Login(CString AgentID,CString Extension,CString AgentGroup,int LoginType=AGENT);//ǩ��
  int Logout();//ǩ��
  int SetIdle();//����
  int SetBusy(CString busyReason);//��æ
  int Answer();//ժ��
  int Hold();//����
  int Retrieve();//�ָ�
  int Reconnect();//ȡ��
  int Hangup();//�һ�
  int DialNum(CString telnum);//�Ⲧ
  int Consult(CString telnum);//��ѯ
  int Transfer(CString telnum);//ת��
  int ConferenceTPin(CString telnum);//TPIN

  int SingleStepTransfer(CString telnum);

  int Conference();//����
  int SetSyncData(CString label, CString value);//������·����
  int SetSyncData(CString kv);//���ö����·����
  CString GetSyncData(CString label);//�õ���·����

  //�೤ϯ����
  int Listen(CString AgentDN);//����
  int ForceBreak(CString AgentDN);//ǿ��
  int BargeIn(CString AgentDN);//ǿ��
  int ForceLogout(CString AgentDN);//ǿ��ǩ��

  //�¼�
  int OnEvent(CString key,CString info);
  int OnAgentStateChange(int state);

  int UpdateGroupInfo(CString groupname);
  int QueryAgentStatus(CString AgentID);
  int QueryAgentStatusByDN(CString telnum);   //ͨ���绰�����ѯ��ϯ��Ϣ
  int QueryCallStatus(CString AgentID);

private:
  bool ISConnEmpty(TConnectionID conn);
  void KickoutMonitor();
};

#endif // !defined(AFX_GENESYSINTERFACE_H__4DE8FC64_BEF7_44B4_9988_3A06A77067E9__INCLUDED_)
