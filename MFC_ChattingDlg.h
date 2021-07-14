
// MFC_ChattingDlg.h: 헤더 파일
//

#pragma once
#include "CClient.h"

#define MAX_NAME_SIZE 256
#define MAX_BUFFER_SIZE 2048

#pragma pack(1)
struct Packet
{
	char name[MAX_NAME_SIZE];
	char buf[MAX_BUFFER_SIZE];
};
#pragma pack()

// CMFCChattingDlg 대화 상자
class CMFCChattingDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCChattingDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CHATTING_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_List;
	CClient m_Client;
	CString name;
	afx_msg void OnEnChangeEditChatText();
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnLbnSelchangeListChat();
};