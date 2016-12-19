#ifndef AFX_MODULE1_H
#define AFX_MODULE1_H

class CControlCenter;

extern BOOL	    g_bWriteLog;          //�Ƿ�д��־
extern LogLevel g_nLogLevel;          //��־��ϸ����1��2��3���� ��ϸ�̶Ƚ���
extern CString	g_LogPath;            //��־·��
extern CFile	  g_File;
extern BOOL     g_bCheckPassword;
extern bool     g_bConnectTServerOK;  //CTI Server����״̬��־

extern CString g_strAgentID;
extern CString g_strCallID;
extern CString g_strBeMonitorAgentID; 
extern CString g_strMonitorAgentDN;	  //����ߵķֻ�
extern CString g_strAgentPwd;
extern CString g_strAgentExt;
extern CString g_strAgentGroup;
extern CallType g_nCallType;
extern CTime	  g_CallBeginTime;
extern CTime   g_CallEndTime;
extern CTime   g_CurStatusBeginTime;
extern CString g_strRouteSource;  
extern CString g_strRouteDest;	
extern TimerOperType g_TimerType;
extern CString g_strANI;
extern CString g_strANITPIN; 
extern CString g_strDNIS;
extern AgentLoginType     g_nLoginType;
extern bool    g_bBargeinFlag;
extern bool    g_bTpinFlag;
extern bool	   g_bTransFlag;
extern bool	   g_bListenFlag;
extern long	   g_nErrorCode ;
extern CString g_strErrorStr ;
extern int     g_nTransTpye;        // ת������ 0-δת��|1-ת����|2-ת��ȡ��
extern bool    g_bSetBusyFlag;      // ԤԼԤԼ��æ��ʶ

extern long		 g_nCTISvrType;       //CTI����������
extern CString g_strCTISvrIp;	      //CTI������IP
extern long	   g_strCTISvrPort;	    //CTI�������˿�
extern CString g_strCTISvrIpBak;    //����CTI������IP
extern long	   g_strCTISvrPortBak;	//����CTI�������˿�

// add by hzd 2016-11-7
extern bool    g_strRecParaSetFlag; //¼���������ñ�ʶ
extern CString g_strRecSvrIp;       //¼��������IP
extern long    g_strRecSvrPort;     //¼���������˿�
extern CString g_strRecUrlPath;     //¼���ļ�url·��
extern CString g_strRecCCID;        //¼�����ݿ��������֤��ʶ
extern CString g_strRecUsrName;     //¼�����ݿ��������֤�û���
extern CString g_strRecPassWord;    //¼�����ݿ��������֤����
extern CString g_strRecUrlFiles;    //¼��url�ļ��б�(JSON��)
extern CTime   g_timeRecEnd;        //�һ�¼������ʱ��
// add by hzd 2016-11-7

extern CString g_strConnID;
extern CString g_strConsultConnID;
extern CString g_strOriConnID;       // ת�ӻ���ѯʱ��ԭConnID add by hzd 2016-11-18
extern TKVList *g_UserData;

extern CString g_PBX;
extern CString g_strBusyReason;
extern CString g_strPasswordReason;   //����ԭ��
extern CString g_strBusyReasonList;
extern CString g_strAllAgents;

extern CControlCenter* g_pCtrlCenter; //
extern CAgentGroupList g_AgentGroupList;

extern bool g_bReconnect;     //����������

extern int  g_nReconnInterval;//�������ʱ�� ��λ����
extern bool g_bSysExit;       //ϵͳ�˳���ʶ
extern char TMessageTypeNames[][64];
extern CString g_RecordIP;
extern UINT    g_RecordPort;
extern CString g_RecordID;

bool OpenLog(CString filename);
void WriteLog(CString logstr,int type,int Level);  
CString SearchStr(CString SourStr,char InterChar,int Position);
void RecordID();
void GetRecFiles(CString CallUUID);
CString HttpGetResponse(CString CallUUID);
CString GetFileList(CString info);
CString base64encode(CString src, int srclen);
#endif