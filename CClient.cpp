#include "pch.h"
#include "CClient.h"


void CClient::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	ShutDown();
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("ERROR : Disconnected From Server!!"));
}

#include "MFC_ChattingDlg.h"
void CClient::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	char buf[MAX_BUFFER_SIZE];
	ZeroMemory(buf, sizeof(buf));
	if (Receive(buf, sizeof(buf)) > 0)
	{
		CMFCChattingDlg* pMain = (CMFCChattingDlg*)AfxGetMainWnd();
	}
	CSocket::OnReceive(nErrorCode);
}
