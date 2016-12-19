#include "stdafx.h"
#include "StateMachine.h"

CStateMachine::CStateMachine()
{
  this->m_CurState = -1;
  this->m_PreState = -1;
  this->m_CurConnID = "";
  this->m_ConsultConnID = "";

}

CStateMachine::~CStateMachine()
{

}



int CStateMachine::QueryCurState()
{
	return m_CurState;
	//return get_m_CurState();
}

int CStateMachine::UpdateState(int state, CString connID)
{
	//��������˵����
	//�ⲿ���ô˷���ȥ����״̬�����ڲ�״̬��״̬������ǰһ��״̬������仯��ǰ��״̬
	//������ɺ�ǰһ״̬����

  m_PreState = this->m_CurState;
  m_CurState = state;

	switch (state)
	{
	case PHONE_STATE_DISABLE:
	{

		break;
	}
	case PHONE_STATE_INIT:
	{

		break;
	}
	case PHONE_STATE_LOGIN:
	{

		break;
	}
	case PHONE_STATE_LOGOUT:
	{

		break;
	}
	case PHONE_STATE_BUSY:
	{

		break;
	}
	case PHONE_STATE_IDLE:
	{
		m_PreState = m_CurState;
		m_CurState = state;

		break;
	}
	case PHONE_STATE_DIALING:
	{

		break;
	}
	case PHONE_STATE_TALKING:
	{

		break;
	}

	case PHONE_STATE_HOLD:
	{

		break;
	}

	case PHONE_STATE_CONFERENCE:
	{

		break;
	}
	}

	return m_PreState;
}
