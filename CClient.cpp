#include "pch.h"
#include "CClient.h"


void CClient::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	ShutDown();
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("ERROR : Disconnected From Server!!"));
}

#include "MFC_ChattingDlg.h"
void CClient::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	char recv_buf[sizeof(Packet)];
	ZeroMemory(recv_buf, sizeof(Packet));
	if (Receive(recv_buf, sizeof(Packet)) > 0)
	{
		CMFCChattingDlg* pMain = (CMFCChattingDlg*)AfxGetMainWnd();
		Packet* recv_packet = (Packet*)recv_buf;
		pMain->m_List.AddString((CString)"[" + recv_packet->name + "]" + " : " + recv_packet->buf);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);
	}
	CSocket::OnReceive(nErrorCode);
}
