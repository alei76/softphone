// CTIInterface.h: interface for the CCTIInterface class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CTIINTERFACE_H__C11F1AD2_5946_44C8_9898_96C080E45DD2__INCLUDED_)
#define AFX_CTIINTERFACE_H__C11F1AD2_5946_44C8_9898_96C080E45DD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CControlCenter;
class CCTIInterface  
{
public:
  CCTIInterface();
  virtual ~CCTIInterface();
private:
  CString m_AgentExt;
  CString m_AgentID;
  CString m_AgentGroup;
  CString m_PeriphID;
  int		m_State;
  CControlCenter  *m_pCC;
  bool	m_bConnectCTIOk;
  bool m_bLonginOK;

public:
  void SetCtrlCenterPtr(CControlCenter *pCC){m_pCC=pCC;};

  virtual bool IsCanBargein(CString ObjAgentID);//�Ƿ�ǿ��

  virtual int GetState(){return m_State;};
  virtual void SetState(int state);

  virtual int ConnectCTIServer(CString HostIP,long Port) = 0;//����CTI

  virtual int Init() = 0;//��ʼ��
  virtual int Exit() = 0;//�˳�

  //��ϯ����
  virtual int Login(CString AgentID,CString Extension,CString AgentGroup,int LoginType) = 0;//ǩ��
  virtual int Logout() = 0;//ǩ��
  virtual int SetIdle() = 0;//����
  virtual int SetBusy(CString busyReason) = 0;//��æ
  virtual int Answer() = 0;//ժ��
  virtual int Hold() = 0;//����
  virtual int Retrieve() = 0;//�ָ�
  virtual int Reconnect() = 0;//ȡ��
  virtual int Hangup() = 0;//�һ�
  virtual int DialNum(CString telnum) = 0;//�Ⲧ
  virtual int Consult(CString telnum) = 0;//��ѯ
  virtual int Transfer(CString telnum) = 0;//ת��
  virtual int ConferenceTPin(CString telnum) = 0; //TPIN

  virtual int SingleStepTransfer(CString telnum) = 0;//��������

  virtual int Conference() = 0;//����

  virtual int SetSyncData(CString label, CString value) = 0;//������·����
  virtual int SetSyncData(CString kv) = 0;//���ö����·����
  virtual CString GetSyncData(CString label) = 0;//�õ���·����


  //�೤ϯ����
  virtual int Listen(CString AgentDN) = 0;//����
  virtual int ForceBreak(CString AgentDN) = 0;//ǿ��
  virtual int BargeIn(CString AgentDN) = 0;//ǿ��

  virtual int ForceLogout(CString AgentDN);//ǿ��ǩ��



  virtual bool GetLoginOkFlag();//��ϯLOGIN�ĳɹ�״̬	
  virtual void SetLoginOkFlag(bool value);

  virtual bool GetSupervisorFlag();//��ϯ�ǲ���Supervisor���	

  virtual int UpdateGroupInfo(CString groupname)=0;

  virtual int QueryAgentStatus(CString AgentID)=0;
  virtual int QueryCallStatus(CString AgentID)=0;

  //�¼�
  virtual int OnEvent(CString key,CString info) = 0;
  virtual int OnAgentStateChange(int state) = 0;

};

#endif // !defined(AFX_CTIINTERFACE_H__C11F1AD2_5946_44C8_9898_96C080E45DD2__INCLUDED_)
