#ifndef AFX_DEFINE_H
#define AFX_DEFINE_H
CString SearchStr(CString SourStr,char InterChar,int Position);

#define CONNECT_CTI_OK		1
#define CONNECT_CTI_FAIL	0

#define OK					1
#define FAIL				0

#define SUCCESS				0
#define FAILURE				-1

#define RETRY_TIMES         3
#define DN_LEN             20      // �绰���볤��

#define TPIN_WAIT_TIME      120			//��λ����

#define UPDATE_GROUP_OVERTIME 400		//��λ������

#define DELAY_EVENT_OVERTIME 500		//��λ������
// ����ͨ���������ȡ¼���ļ���ʱ����
#define GET_REC_INFO_WAIT_TIME 10   //��λ����

//��绰��״̬
typedef enum _Phone_State
{
	PHONE_STATE_DISABLE	=-1,
	PHONE_STATE_INIT=0,
	PHONE_STATE_LOGIN=1,	
	PHONE_STATE_LOGOUT=2,	
	PHONE_STATE_BUSY=3,	
	PHONE_STATE_IDLE=4,	
	PHONE_STATE_RING=5,
	PHONE_STATE_TALKING=6,
	PHONE_STATE_CONSULT=7,
	PHONE_STATE_ANSWER_CONSULT=8,
	PHONE_STATE_DIALING=9,	
	PHONE_STATE_CONFERENCE=10,	
	PHONE_STATE_HOLD=11,
	PHONE_STATE_LISTEN=12,	
	PHONE_STATE_BELISTEN=13,	
	PHONE_STATE_AFTERTALK=14,
	PHONE_STATE_TPIN=15
}Phone_State;

//ʱ�Ӳ�������
typedef enum _TimerOperType
{
	TIMER_OPER_INIT=0,
	TIMER_OPER_START=1,
	TIMER_OPER_STOP=2,
	TIMER_OPER_PAUSE=3,
	TIMER_OPER_RESTART=4,
	TIMER_OPER_SHOWSTATUS=5

}TimerOperType;

//�������¼�����
typedef enum _DispatchEventType
{
	DISPATCH_EVENT_LOGIN=0,
	DISPATCH_EVENT_LOGOUT=1,
	DISPATCH_EVENT_ACW=2,
	DISPATCH_EVENT_AGENTIDLE=3,
	DISPATCH_EVENT_AGENTBUSY=4,
	DISPATCH_EVENT_ABANDON=5,
	DISPATCH_EVENT_ESTABLISHED=6,
	DISPATCH_EVENT_HANGUP=7,
	DISPATCH_EVENT_HELD=8,
	DISPATCH_EVENT_MONITORCALL=9,
	DISPATCH_EVENT_NEWCALL=10,
	DISPATCH_EVENT_RETRIEVED=11,
	DISPATCH_EVENT_AFTERTPIN=12,
	DISPATCH_EVENT_SERVICEEND=13,
	DISPATCH_EVENT_CHECKPASSWORD=14,
	DISPATCH_EVENT_QUERYAGENT=15,
	DISPATCH_EVENT_QUERYCALL=16,
	DISPATCH_EVENT_CONFERENCE=17,
	DISPATCH_EVENT_CONFERENCEEND=18,
	DISPATCH_EVENT_CALLTYPECHANGED=19,
	DISPATCH_EVENT_DIALING=20,
	DISPATCH_EVENT_RECORD=21,
	DISPATCH_EVENT_ERROR=26	
}DispatchEventType;

//�û��Զ�����Ϣ
#define WM_STATE_CHANGE WM_USER + 300   //״̬�仯
#define WM_DISPATCH_EVENT WM_USER + 310  //�¼�
#define WM_START_TPIN_TIMER WM_USER + 311  //�¼�
#define WM_END_TPIN_TIMER WM_USER + 312  //�¼�

//CTI�м�����Ͷ���
typedef enum _CTIServerType
{
	GENESYS=0,
	OTHERCTI=1
}CTIServerType;

//��ϯ��¼����
typedef enum _AgentLoginType
{
	AGENT=0,
	SUPERVISOR=1
}AgentLoginType;

//��������
typedef enum _OperationType
{
	OPER_LOGIN=0,
	OPER_LOGOUT=1,
	OPER_ANSWER=2,
	OPER_DIAL=3,
	OPER_TRANSFER=4,
	OPER_SINGLE_STEP_TRANSFER=5,
	OPER_CONSULT=6,
	OPER_CONFERENCE=7,
	OPER_HOLD=8,
	OPER_SETONEUSERDATA=9,
	OPER_SETUSERDATA=10,
	OPER_GETONEUSERDATA=11,
	OPER_GETSTATUS=12,
	OPER_RELEASE=13,
	OPER_RECONNECT=14,
	OPER_SETIDLE=15,
	OPER_SETBUSY=16,
	OPER_TPIN=17,
	OPER_LISTEN=18,
	OPER_BARGEIN=19,
	OPER_RETRIEVE=20,
	OPER_FORCEBREAK=21,
	OPER_UPDATEGROUPINFO=22,
	OPER_QUERYAGENT=23,
	OPER_QUERYCALL=24,
	OPER_FORCELOGOUT=25,
  // ��ȡ¼��rul�ļ��б� add by hzd 2016-11-7
  OPER_GETRECFILES=26

}OperationType;

//��־����
typedef enum _LogType
{
	SYSTEM_LOG=0, //ϵͳ
	INFO_LOG=1,	//��Ϣ
	ERROR_LOG=2,  //����
	WARNING_LOG=3 //����
}LogType;

//��־����
typedef enum _LogLevel
{
	BASE_LOG_LEVEL=1,
	RUN_LOG_LEVEL=2,
	DEBUG_LOG_LEVEL=3
}LogLevel;

//��������
typedef enum _CallType
{
	CALL_TYPE_UNKNOWN=0,  //δ֪
	CALL_TYPE_INTERNAL=1,   //���ߺ���
	CALL_TYPE_INBOUND=2,    //inbound����
	CALL_TYPE_OUTBOUND=3,   //outbound����
	CALL_TYPE_CONSULT=4     //��ѯ����
}CallType;

//ת������
typedef enum _TransType
{
	TRANS_TYPE_AGENT=0,
	TRANS_TYPE_GROUP=1,
	TRANS_TYPE_IVR=2
}TransType;

//��·����
class CUserData
{
public:
	CString Key;
	CString Value;
public:
	CUserData()
	{
		Key		= ""	;
		Value	= ""	;
	}
public:
	//Operator
	void operator=(const CUserData& src)
	{
		Key		= src.Key	;
		Value	= src.Value	;
	};
	CUserData(CUserData& src)
	{
		Key		= src.Key	;
		Value	= src.Value	;
	};
};
typedef CArray<CUserData,CUserData> CUserDataList;

//������Ϣ
class CCallInfo
{//call info
public:
	CString	UniqueObjID;
	CString CallID;
	CString ANI;
	CString DNIS;
	int	CallState;  // 0:no call 1:has call
	int CallType;
	CUserDataList UserData;
public:
	CCallInfo()
	{
		UniqueObjID	= ""	;
		CallID		= ""	;
		ANI			= ""	;
		DNIS		= ""	;
		CallState	= 0	;
		CallType	=0		;
		UserData.RemoveAll();
	}
	void ClearAllData() 
	{
		UserData.RemoveAll();
	};
	void ClearCall() 
	{
		UniqueObjID	= ""	;
		CallID		= ""	;
		ANI			= ""	;
		DNIS		= ""	;
		CallState	= 0	;
		CallType	= 0		;
		UserData.RemoveAll();
	};
	void AddData(CUserData data)
	{
		bool bFind=false;
		int nNum=UserData.GetSize();
		while(nNum--)
		{
			CUserData ud=UserData.GetAt(nNum);	
			if (0==ud.Key.CompareNoCase(data.Key)) 
			{
				UserData.SetAt(nNum,data);
				bFind=true;
			}
		}	
		if(!bFind)
			UserData.Add(data);
	}
	void DeleteData(CUserData data)
	{
		int nNum=UserData.GetSize();
		while(nNum--)
		{
			CUserData ud=UserData.GetAt(nNum);	
			if (0==ud.Key.CompareNoCase(data.Key)) 
			{
				UserData.RemoveAt(nNum);
			}
		}	
	}
public:
	//Operator
	void operator=(const CCallInfo& src)
	{
		UniqueObjID	= src.UniqueObjID	;
		CallID		= src.CallID	;
		ANI			= src.ANI		;
		DNIS		= src.DNIS		;
		CallState	= src.CallState	;
		CallType	= src.CallType	;
		UserData.Copy(src.UserData)	;
	};
	CCallInfo(CCallInfo& src)
	{
		UniqueObjID	= src.UniqueObjID	;
		CallID		= src.CallID	;
		ANI			= src.ANI		;
		DNIS		= src.DNIS		;
		CallState	= src.CallState	;
		CallType	= src.CallType	;
		UserData.Copy(src.UserData)	;
	};
};
typedef CArray<CCallInfo,CCallInfo> CCallList;

//��ϯ��Ϣ
class CAgentInfo
{//monitor agent
public:
	CString UniqueObjectID;
	CString AgentID;
	CString AgentName;
	CString AgentExtension;
	CString AgentInstrument;
	int	AgentState;   //0:no login  2:idle  3:busy
	CString Extension;
	CString SkillGroup;
	int		IsSupervisor;
	//about current call
	CCallInfo CallInfo;

public:
	CAgentInfo()
	{
		UniqueObjectID	="";
		AgentID			="";
		AgentName		="";
		AgentExtension	="";
		AgentInstrument	="";
		AgentState		=0;
		Extension		="";
		SkillGroup		="";
		IsSupervisor	=0;
	}

public:
	//Operator
	void operator=(const CAgentInfo& src)
	{
		UniqueObjectID	=src.UniqueObjectID;
		AgentID			=src.AgentID;
		AgentName			=src.AgentName;
		AgentExtension	=src.AgentExtension;
		AgentInstrument	=src.AgentInstrument;
		AgentState		=src.AgentState;
		Extension		=src.Extension;
		SkillGroup		=src.SkillGroup;
		IsSupervisor	=src.IsSupervisor;
		CallInfo		=src.CallInfo;
	};
	CAgentInfo(CAgentInfo& src)
	{
		UniqueObjectID	=src.UniqueObjectID;
		AgentID			=src.AgentID;
		AgentName			=src.AgentName;
		AgentExtension	=src.AgentExtension;
		AgentInstrument	=src.AgentInstrument;
		AgentState		=src.AgentState;
		Extension		=src.Extension;
		SkillGroup		=src.SkillGroup;
		IsSupervisor	=src.IsSupervisor;
		CallInfo		=src.CallInfo;
	};
};

typedef CArray<CAgentInfo,CAgentInfo> CAgentInfoList;

//��ϯ��
class CAgentGroup
{
public:
	CString GroupName;
	CString GroupIndex;
	CString GroupID;
	CAgentInfoList agtList;
public:
	CAgentGroup()
	{
		GroupName		= ""	;
		GroupID	= ""	;
		GroupIndex	= ""	;
	}
	void AddAgent(CAgentInfo agtInfo)
	{
		agtList.Add(agtInfo);
	}

	void UpdateAgentStatus(CString AgtID,CString AgtExt,int AgtStatus)
	{
		for(int i=0;i<agtList.GetSize();i++)
		{
			CAgentInfo agtinfo = agtList.GetAt(i);
			if(AgtID==agtinfo.AgentID)
			{
				agtinfo.AgentState = AgtStatus;
				agtinfo.AgentExtension = AgtExt;
				agtList.SetAt(i,agtinfo);
				break;
			}
		}
	}

	void UpdateCallStatus(CString AgtID,CString AgtExt,int CallStatus)
	{
		for(int i=0;i<agtList.GetSize();i++)
		{
			CAgentInfo agtinfo = agtList.GetAt(i);
			if(AgtID==agtinfo.AgentID)
			{
				agtinfo.CallInfo.CallState = CallStatus;
				agtinfo.AgentExtension = AgtExt;
				agtList.SetAt(i,agtinfo);
				break;
			}
		}
	}

public:
	//Operator
	void operator=(const CAgentGroup& src)
	{
		GroupName	= src.GroupName	;
		GroupID		= src.GroupID	;
		GroupIndex		= src.GroupIndex	;
		agtList.Copy(src.agtList) 	;
	};
	CAgentGroup(CAgentGroup& src)
	{
		GroupName	= src.GroupName	;
		GroupID		= src.GroupID	;
		GroupIndex		= src.GroupIndex	;
		agtList.Copy(src.agtList) 	;
	};
};

//��ϯ���б�
class CAgentGroupList
{
public:
	typedef CArray<CAgentGroup,CAgentGroup> GroupList;
	GroupList  agtGroupList;
public:
	CAgentGroupList()
	{
	}	
	CAgentGroupList(CAgentGroupList& src)
	{
		agtGroupList.Copy(src.agtGroupList);
	};
	
public:
	int GetCount() {return agtGroupList.GetSize();};

	void AddGroup(CAgentGroup agtGroup)
	{
		if (!IsExist(agtGroup.GroupID))
		{
			agtGroupList.Add(agtGroup);
		}
		
	};

	void SetGroup(CAgentGroup agtGroup)
	{
		for(int i=0;i<agtGroupList.GetSize();i++)
		{
			CAgentGroup ag = agtGroupList.GetAt(i);
			if(agtGroup.GroupID==ag.GroupID)
			{
				agtGroupList.SetAt(i,agtGroup);
				break;
			}
		}
	};

	bool IsExist(CString groupid)
	{
		for(int i=0;i<agtGroupList.GetSize();i++)
		{
			CAgentGroup ag = agtGroupList.GetAt(i);
			if(groupid==ag.GroupID)
				return true;
		}
		return false;
	}

	void ParseInfo(CString info)
	{//20080428011659,�ͷ��೤,8001,κ�໪,P_monitor_1,89303|20080429012490,������ͨ��ϯ,1006,����,P_agent_1,89303
		if(info.IsEmpty())
			return;
		agtGroupList.RemoveAll();

		CString tmpstr;
		int i=0;
		tmpstr = SearchStr(info+"|",'|',i); 
		while(!tmpstr.IsEmpty())
		{
			AddAgent(tmpstr);
			i++;
			tmpstr = SearchStr(info+"|",'|',i); 
		}

	}

	CAgentGroup GetGroup(CString groupname)
	{
		CAgentGroup ag ;
		for(int i=0;i<agtGroupList.GetSize();i++)
		{
			CAgentGroup tmpag = agtGroupList.GetAt(i);
			if(groupname==tmpag.GroupName)
			{
				ag=tmpag;
				break;
			}
		}
		return ag;
	}

	void AddAgent(CString infostring)
	{//20080429012490,������ͨ��ϯ,1006,����,P_agent_1,89303|

		CString groupid = SearchStr(infostring+",",',',4);
		CString groupindex = SearchStr(infostring+",",',',5);
		CString groupname = SearchStr(infostring+",",',',1);
		CString agentid = SearchStr(infostring+",",',',2);
		CString agentname = SearchStr(infostring+",",',',3);
		if(groupid.IsEmpty()||agentid.IsEmpty())
			return;

		bool bfind = false;
		for(int i=0;i<agtGroupList.GetSize();i++)
		{
			CAgentGroup ag = agtGroupList.GetAt(i);
			if(groupid==ag.GroupID)
			{
				bfind=true;
				CAgentInfo ai;
				ai.AgentID = agentid;
				ai.AgentName=agentname;
				ag.AddAgent(ai);
				agtGroupList.SetAt(i,ag);
				break;
			}
		}

		if (!bfind)
		{
			CAgentGroup ag ;
			ag.GroupID = groupid;
			ag.GroupName = groupname;
			ag.GroupIndex = groupindex;
			CAgentInfo ai;
			ai.AgentID = agentid;
			ai.AgentName=agentname;
			ag.AddAgent(ai);
			agtGroupList.Add(ag);
		}
	}
};


#endif