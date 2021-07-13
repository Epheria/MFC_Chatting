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
	char buf[MAX_BUFFER_SIZE];
	ZeroMemory(buf, sizeof(buf));
	if (Receive(buf, sizeof(buf)) > 0)
	{
		CMFCChattingDlg* pMain = (CMFCChattingDlg*)AfxGetMainWnd();
	}
	CSocket::OnReceive(nErrorCode);
}
